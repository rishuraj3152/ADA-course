#include<bits/stdc++.h>
#include<cstdlib>
#include<string>

//not for negative numbers

using namespace std;

template <class X>
class Tempstack
{
	X *arr;
	int top;
	int capacity;


public:
	Tempstack(int size);

	void push(X);
	X pop();
	X peek();

	int size();
	bool isEmpty();
	bool isFull();
	void display();
};

template <class X>
Tempstack<X>::Tempstack(int size)
{
	arr = new X[size];
	capacity = size;
	top = -1;
}

template <class X>
void Tempstack<X>::push(X x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	arr[++top] = x;
}

template <class X>
X Tempstack<X>::pop()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[top--];
}

template <class X>
X Tempstack<X>::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

template <class X>
int Tempstack<X>::size()
{
	return top + 1;
}


template <class X>
bool Tempstack<X>::isEmpty()
{
	return top == -1;
}


template <class X>
bool Tempstack<X>::isFull()
{
	return top == capacity - 1;
}

template <class X>
void Tempstack<X>::display()
{
    int temp=top;
    while(temp!=-1)
    {
        cout<<arr[temp]<<endl;
        temp--;
    }
}

int prec(char c)
{
	if(c == '^')
	return 3;
	else if(c == '*' || c == '/')
	return 2;
	else if(c == '+' || c == '-')
	return 1;
	else
	return -1;
}

bool checkparenthesis(string s)
{
    Tempstack <char> st(100);
    char x;
    int j=0;
    int l=s.length();
    for (int i=0; i<l; i++)
    {
            if (s[i]=='('||s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
                continue;
            }
            if (st.isEmpty())
               return false;
            switch (s[i])
            {
            case ')':
                x = st.peek();
                st.pop();
                if (x=='{' || x=='[')
                    return false;
                break;

            case '}':
                x = st.peek();
                st.pop();
                if (x=='(' || x=='[')
                    return false;
                break;

            case ']':
                x = st.peek();
                st.pop();
                if (x =='(' || x == '{')
                    return false;
                break;
            }
        }
    return (st.isEmpty());
}

string InfixtoPostfix(string s)
{
    Tempstack <char> st(100);
    st.push('(');
	int l = s.length();
	string ns;
	for(int i = 0; i < l; i++)
	{
		if(isalnum(s[i]))
           {
                ns+=s[i];
           }
		else if(s[i] == '(')
        {
             st.push('(');
        }
        else if(s[i] == ')')
		{
			while(st.peek() != '(' )
			{
				char c = st.peek();
				st.pop();
				ns+=' ';
                ns += c;
			}
			if(st.peek() == '(')
			{
				char c = st.peek();
				st.pop();
			}
		}
		else
        {
            ns+=' ';
			while(st.peek() != '(' && prec(s[i]) <= prec(st.peek()))
			{
				char c = st.peek();
				st.pop();
				ns += c;
				ns+=' ';
			}
			st.push(s[i]);
		}
		cout<<"contents of stack:"<<endl;
		st.display();
		cout<<"intermediate postfix expn:"<<ns<<endl;
	}

    while(st.peek() != '(')
	{
		char c = st.peek();
		st.pop();
		ns+=' ';
		ns += c;
	}

    return ns;
}

int Evaluatepostfix(string px)
{
    int i;
    Tempstack <int> ts(50);
    for(i=0;i<px.length();i++)
    {
        if(px[i]==' ')continue;
        if(isdigit(px[i]))
        {
            int num=0;
            while(isdigit(px[i]))
            {
                num=(num*10)+(int)(px[i]-'0');
                i++;
            }i--;
            ts.push(num);
            cout<<"contents of stack:"<<endl;
            ts.display();
        }
        else
        {
            int a=ts.pop();
            int b=ts.pop();
            cout<<"a="<<a<<"  b="<<b<<endl;
            cout<<"contents of stack:"<<endl;
            ts.display();
            switch (px[i])
            {
            case '+':
                ts.push(b+a);
                break;
            case '-':
                ts.push(b-a);
                break;
            case '*':
                ts.push(b*a);
                break;
            case '/':
                ts.push(b/a);
                break;
            case '^':
                ts.push(pow(b,a));
                break;
            }
        }
    }
    return ts.pop();
}

int main()
{
	string infix, postfix, input;
    cout<<"Enter any infix expression (don't use any braces other than the smaller one) : "<<endl;
    cin >> infix;
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(infix[i]=='(' || infix[i]=='{' || infix[i]=='[' || infix[i]==')' || infix[i]=='}' || infix[i]==']')
        {
            input+=infix[i];
        }
        i++;
    }
    if(checkparenthesis(input))
    {
       postfix=InfixtoPostfix(infix);
        cout<<"The corresponding postfix expression is : "<<endl;
        cout<<postfix<<endl;
        cout<<"postfix value:"<<Evaluatepostfix(postfix)<<endl;
    }
    else
        cout<<"the entered expression has not balanced parenthesis";
    return 0;
}
