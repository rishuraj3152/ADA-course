#include <iostream>
#define MAX 20
using namespace std;

class stack{
	int s[MAX];
	int top;
	public:
	stack *next;
	stack()
	{
		top = -1;
		next = NULL;
	}
	bool is_empty()
	{
		if(top == -1)
			return true;
		return false;
	}
	void push(int item)
	{
		if(top == MAX - 1){
			cout<<"OVERFLOW \n";
			//throw std::overflow_error("Stack overflow");
			return;
		}
		++top;
		s[top] = item;
	}
	int pop(int item)
	{
		if (is_empty()){
			cout<<"Underflow";
			return -1;
		}
		return s[top--];
	}
	void display()
	{
		for(int i = top; i >= 0; --i){
			cout<<"|\t"<<s[i]<<"\t|\n";
			cout<<" ---------------\n";
		}
	}
};

class queue{
	stack *front;
	stack *rear;
	public:
	queue()
	{
		front = NULL;
		rear = NULL;
	}
	bool is_empty()
	{
		if (front == NULL) 
			return true;
		return false;
	}
	void insert(stack *s)
	{
		if(front == NULL){
			front = rear = s;
			return;
		}
		rear->next = s;
		rear = rear->next;
	}
	stack* dequeue()
	{
		stack *temp = NULL;
		if(is_empty()){
			cout<<"Underflow\n";
			return temp;
		}
		temp = front;
		front = front->next;
		if(front == NULL)
			rear = NULL;
		return temp;
	}
	void display()
	{
		stack *i = NULL;
		i = front;
		if(is_empty())
			cout<<"Empty\n";
		while(i != NULL){
			i->display();
			if(i->next != NULL)
				cout<<" \t|\n \tV\n";
			i = i->next;
		}
		
	}
};

int main()
{
	queue q;
	stack *s;
	int n, n1, data, ch = 0;
	do{
		cout<<"1.Enqueue\n2.Dequeue\n0.Exit\nchoice:";
		cin>>ch;
		switch(ch){
		case 1:	
			cout<<"Enter no of stacks to be added in queue:";
			cin>>n;
			for (int i = 0; i < n; ++i){
				cout<<"\nEnter no of elements in stack "<<i+1<<": ";
				cin>>n1;
				s = new stack();
				cout<<"elements:";
				for (int j = 0; j < n1; ++j){
					cin>>data;
					s->push(data);
				}
				q.insert(s);
				cout<<"\nCurrent instance of queue is:\n";
				q.display();
			}
			break;
		case 2:	s = q.dequeue();
			if (s == NULL)
				break;
			cout<<"Following stack is removed from queue:\n";
			s->display();
			cout<<"\nCurrent instance of queue is:\n";
			q.display();
			delete s;
			s = NULL;
			break;
		}	
	}while(ch != 0);
	return 0;
}
