#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node st;
int main()
{
    int n,m,count=0,count1=0,*flag;
	st *head=NULL,*head2=NULL,*ptr=NULL;
	printf("enter size of first linked list");
	scanf("%d",&n);
	flag=(int*)calloc(1000000,sizeof(int));
	while(n)
	{
		st* newNode=(st*)malloc(sizeof(st));
		scanf("%d",&(newNode->data));
		newNode->next=NULL;
		if(head==NULL)
		{
			head=newNode;
			newNode->next=head;
		}
		else
		{
                ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                newNode->next=head;
                ptr->next=newNode;
		}
		n--;
	}

	printf("enter size of second linked list ");
	scanf("%d",&m);
	int temp=m;
	while(m)
	{
		st* newNode=(st*)malloc(sizeof(st));
		scanf("%d",&(newNode->data));
		newNode->next=NULL;
		if(head2==NULL)
		{
			head2=newNode;
			newNode->next=head2;
		}
		else
		{
		    ptr=head2;
		    while(ptr->next!=head2)
                {
                    ptr=ptr->next;
                }
			newNode->next=head2;
			ptr->next=newNode;

		}
		m--;
	}


    ptr=head;
    st *ptr2=head2;
    st *res=NULL;
    do
    {
        while(1)
            {
                if(ptr->data==ptr2->data && flag[ptr->data]!=1)
                {
                    flag[ptr->data]=1;
                    st* newnode=(st*)malloc(sizeof(st));
                    newnode->data=ptr->data;
                    newnode->next=NULL;
                    if(res==NULL)
                    {
                        res=newnode;
                        res->next=res;
                    }
                    else
                    {
                            st *p=res;
                            while(p->next!=res)
                            {
                                p=p->next;
                            }
                            newnode->next=p->next;
                            p->next=newnode;
                    }
                    count++;
                    ptr2=ptr2->next;
                    break;
                }
                ptr2=ptr2->next;
                count++;
                if(count==temp)
                    {break;}
            }
            ptr=ptr->next;
            count=0;
    }
    while(ptr!=head);


    printf("\n");
    ptr=res;
    printf("*******final circular linked list********\n");
    if(ptr!=NULL)
    {
        while(ptr->next!=res)
        {
            printf("%d->\t",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
    else
    {
        printf("\tThere is no intersection element\t");
    }
    free(flag);
    free(head);
    free(head2);
    return 0;
}
