#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node()
    {
        data=0;
        next = NULL;
    }
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

class CircList {
  public:
      node* head;
    void createList();
    void display();

    void addAtFront(int);
    //function to check whether Linked list is empty
    bool isEmpty();
    //function to add Node at the End of list
    void addAtEnd(int);
    //function to search a value
    node* search(int);
    //function to delete any Node
    int deleteNode(int);
    int deleteFront();
    int deleteEnd();

    CircList() {
    head = NULL;
    }
};
void CircList::createList()
{
    int d;
    cout<<"enter -1 to end"<<endl;
    cout<<"enter the data"<<endl;
    cin>>d;
    while(d!=-1)
    {
        node *nnode=new node(d);
        if(head==NULL)
        {
            head=nnode;
            nnode->next=head;
        }
        else
        {
            node *temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=nnode;
            nnode->next=head;
        }
        cin>>d;
    }
}
void CircList :: display()
{
    if(head==NULL)
    {
        cout<<"list is empty";
        return;
    }
    node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<temp->data;
}
void CircList :: addAtFront(int data)
{
    node *nnode=new node(data);
  if(head== NULL)
    {
    nnode->next = head;
    head = nnode;
  }
  else {
    nnode->next = head;
    node *ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next = nnode;
    head=nnode;
  }
}
void CircList :: addAtEnd(int data)
{
    node *nnode=new node(data);
    if(head == NULL) {
        head=nnode;
        nnode->next = head;
  }
  else {
    nnode->next = head;
    node *ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next = nnode;
  }
}
node* CircList :: search(int x) {
    node *ptr = head;
  while(ptr->next != head  && ptr->data != x) {
    //until we reach the end or we find a Node with data x, we keep moving
    ptr = ptr->next;
  }
  return ptr;
}
int CircList :: deleteNode(int x) {
  //searching the Node with data x
  node *n = search(x);
  node *ptr = head;
  if(ptr == NULL) {
    cout << "List is empty";
    return -1;
  }
  else if(ptr == n) {
    int r=deleteFront();
    return r;
  }
  else {
    while(ptr->next != n) {
      ptr = ptr->next;
    }
    ptr->next = n->next;
    int r=n->data;
    free(n);
    return r;
  }
}
int CircList :: deleteEnd() {
  node *ptr = head;
  if(ptr == NULL) {
    cout << "List is empty";
    return -1;
  }
  else if(ptr->next==head) {
        int r=ptr->data;
    free(ptr);
    head=NULL;
    return r;
  }
  else {
    while(ptr->next->next != head) {
      ptr = ptr->next;
    }
    node* temp=ptr->next;
    ptr->next = head;
    int r=temp->data;
    free(temp);
    return r;
  }
}

int CircList :: deleteFront() {

    node *ptr = head;
  if(ptr == NULL) {
    cout << "List is empty";
    return -1;
  }
  else if(ptr->next==head) {
        int r=ptr->data;
    free(ptr);
    head=NULL;
    return r;
  }
  else {
    while(ptr->next != head) {
      ptr = ptr->next;
    }
    ptr->next = head->next;
    node* temp=head;
    head=head->next;
    int r=temp->data;
    free(temp);
    return r;
  }
}
int main()
{
    //node *n=new node();
    CircList cl;
    int option,data;
    node *tmp;
    while(1)
    {
        cout<<"\n*****circular linked list*******\n";
        cout<<"1.create a list\n2.Display a list\n";
        cout<<"3.Add a node at beginning\n";
        cout<<"4.Add a node at end\n";
        cout<<"5.Delete a node from the beginning\n";
        cout<<"6.Delete a node from tne end\n";
        cout<<"7.Delete a particular node\n";
        cout<<"0.Exit"<<endl;
        cout<<"enter your option";
        cin>>option;
        switch(option)
        {
            case 1:
                cl.createList();
                break;
            case 2:
                cl.display();
                break;
            case 3:
                cout<<"enter data\n";
                cin>>data;
                cl.addAtFront(data);
                break;
            case 4:
                cout<<"enter data\n";
                cin>>data;
                cl.addAtEnd(data);
                break;
            case 5:
                data=cl.deleteFront();
                if(data!=-1)
                cout<<data<<" node deleted"<<endl;
                break;
            case 6:
                data=cl.deleteEnd();
                if(data!=-1)
                cout<<data<<" node deleted"<<endl;
                break;
            case 7:
                cout<<"enter the node:";
                cin>>data;
                data=cl.deleteNode(data);
                if(data!=-1)
                cout<<data<<" node deleted"<<endl;
                break;
            case 0:
                exit(0);
            default:
                cout<<"enter correct input";
        }
}
return 0;
}
