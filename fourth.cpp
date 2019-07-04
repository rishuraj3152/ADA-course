#include<iostream>
#include<cstring>

using namespace std;

class String
{
    int length;
    char *ptr;
public:
    String()
    {
        cout<<"memory allocated inside default constructor"<<endl;
        length=100;
        ptr=new char[length];
    }
    String(char *arr)
    {
        cout<<"memory allocated inside parameterized constructor"<<endl;
        length=100;
        arr=new char[length];
        ptr=arr;
    }
    char* concat(char *str1,char *str2)
    {
        return strcat(str1,str2);

    }
};
int main()
{
    char *st1,*st2;
    st1=new char[100];
    st2=new char[100];
    String sttring;
    String str("ranveer");
    cout<<"enter two strings to concatenate:"<<endl;
    cin>>st1>>st2;
    cout<<"after concatenation string is:"<<str.concat(st1,st2);
    return 0;
}
