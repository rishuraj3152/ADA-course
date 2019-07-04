#include <iostream>

using namespace std;

class Publication
{
protected:
    string title;
    float price;
    int copies;
public:
    void sellCopy(){}
};

class Book: public Publication
{
    string author;
public:
    void orderCopies(){}
};

class Magazine: public Publication
{
protected:
    int orderQty=100;
    int currIssue=10;
public:
    Magazine(){};
    Magazine(int oq,int ci){orderQty=oq;currIssue=ci;}
    void adjustQty(){}
    void recvNewIssue(){orderQty++;cout<<"orderQty="<<orderQty;}
};
class DiscMag: public Magazine
{
public:
    DiscMag(){};
    DiscMag(int a,int b):Magazine(a,b){}
    void recvNewIssue()
    {
        orderQty++;
        cout<<"check if the disks correctly attached or not?";
    }
};
int main()
{
    string ans;
    DiscMag dscmag(23,10);
    Magazine mg;
    cout<<"does the new stock have disks??";
    cin>>ans;
    if(ans=="y")dscmag.recvNewIssue();
    else mg.recvNewIssue();
    return 0;
}
