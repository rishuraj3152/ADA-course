#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int front=-1,rear=-1;

struct node
{
    int data;
    int priority;
};

bool isfull()
{
    if(rear>=MAX)return true;
    return false;
}
bool isempty()
{
    if(front==-1 || rear==-1)return true;
    else if(front>rear)return true;
    return false;
}
void pqdisplay(struct node pq[])
{
    if(isempty())
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"Data\tPriority"<<endl;
    for(int i=front;i<=rear;i++)
    {
        cout<<pq[i].data<<"\t"<<pq[i].priority<<endl;
    }
}
void pqinsert(struct node pq[],int d,int p)
{
    if(isfull())
    {
        cout<<"priority queue is full";
        return;
    }
    if(front==-1 && rear==-1)
        {front++;rear++;}
    else
        rear++;
    pq[rear].data=d;
    pq[rear].priority=p;
    pqdisplay(pq);
}
void pqmindelete(struct node pq[])
{
    int i,min=9999,mark;
    if(isempty())
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    for(i=front;i<=rear;i++)
    {
        if(pq[i].priority<min)
        {
            min=pq[i].priority;
            mark=i;
            cout<<"minimum index: "<<mark<<endl;
        }
    }
    if(mark==rear)
    {
        rear--;
    }
    for(i=mark;i<rear;i++)
    {
        pq[i].data=pq[i+1].data;
        pq[i].priority=pq[i+1].priority;
        rear--;
    }
    pqdisplay(pq);
}
void pqempty(struct node pq[])
{
    if(isempty())
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    front=-1;
    rear=-1;
    cout<<"queue is emptied"<<endl;
    pqdisplay(pq);
}
int main()
{
    int option,data,priority,i;
    struct node pq[100];
    cout<<"********PRIORITY QUEUE*********"<<endl;
    cout<<"1.insert"<<endl;
    cout<<"2.delete minimum"<<endl;
    cout<<"3.empty"<<endl;
    cout<<"4.exit"<<endl;
    cout<<"enter ur choice";
    cin>>option;
    while(option!=4)
    {
        switch(option)
        {
            case 1:
                cout<<"enter data";
                cin>>data;
                cout<<"enter priority";
                cin>>priority;
                pqinsert(pq,data,priority);
                break;
            case 2:
                pqmindelete(pq);
                break;
            case 3:
                pqempty(pq);
                break;
            default:
                cout<<"enter correct choice"<<endl;
        }
        cout<<"********PRIORITY QUEUE*********"<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.delete minimum"<<endl;
        cout<<"3.empty"<<endl;
        cout<<"4.exit"<<endl;
        cout<<"enter ur choice";
        cin>>option;
    }

    return 0;
}
