#include<time.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class Money
{
public:
    int basefee;
public:
    Money(){basefee=1000;}
};

class Person
{
public:
    int patientId;
    string hospname;
    int yoj;
    string patadd;
    int medfee;
};
class Patient: public Person
{
public:
    Patient()
    {
        patientId=123;
        hospname="null";
        yoj=0;
        patadd="null";
        medfee=0;
    }
    void setData(string hn,int y,string add)//multiple methods for setting
    {
        hospname=hn;
        yoj=y;
        patadd=add;
    }
    void getData()//multiple methods for getting
    {
        cout<<"hospital name:"<<hospname<<endl;
        cout<<"year of joining:"<<yoj<<endl;
        cout<<"address of patient:"<<patadd<<endl;
    }
    int calmedfee(Money mn)
    {
        time_t rawtime=time(0);
        struct tm timeinfo;
        char *buffer;

        //buffer=array;
        timeinfo = *localtime(&rawtime);
        strftime(buffer,100,"%Y",&timeinfo);
        cout<<buffer;
        int val=atoi(buffer);
        val-=yoj;
        medfee=val*mn.basefee;
        return medfee;
    }
};
int main()
{
    string hname;
    int yoj;
    string add;
    Patient pt;
    cout<<"enter hospital name:";
    getline(cin,hname);
    cout<<"enter year of joining:";
    cin>>yoj;
    cout<<"enter address of patient:";
    cin.ignore();
    getline(cin,add);
    pt.setData(hname,yoj,add);
    pt.getData();
    Money mon;
    cout<<"total medical fee"<<pt.calmedfee(mon);
    return 0;
}
