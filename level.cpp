#include<iostream>
using namespace std;

typedef struct node {
   int value;
   struct node *left, *right;
}node;


node *getNewNode(int value) {
   node *new_node = new node;
   new_node->value = value;
   new_node->left = NULL;
   new_node->right = NULL;
   return new_node;
}

int getLevel(node *ptr,int val,int level) {
   if (ptr == NULL)
      return 0;

   if (ptr->value == val)
      return level;

   int d=getLevel(ptr->left, val, level+1);
   if(d!=0)
        return d;
   d = getLevel(ptr->right, val, level+1);
        return d;
}



node *createTree() {
   node *root = getNewNode(31);
   cout<<"\t\t\t31"<<endl;
   root->left = getNewNode(16);
   root->right = getNewNode(52);
   cout<<endl<<"\t16\t\t\t\t52"<<endl;
   root->left->left = getNewNode(7);
   root->left->right = getNewNode(24);
   cout<<endl<<"7\t\t24"<<endl;
   root->left->right->left = getNewNode(19);
   root->left->right->right = getNewNode(29);
   cout<<endl<<"\t19\t\t29"<<endl;
   return root;
}


int main() {
   node *root = createTree();
   int val;
   do{
   cout<<endl<<"enter the node to find out ur and node level both"<<endl;
   cout<<"enter -1 to exit"<<endl;
   cin>>val;
   if(val>=0)
   {
       int level = getLevel(root,val,1);
        cout<<"\nLevel of "<<val<<" is "<<level<<endl;
   }
   }while(val!=-1);
   return 0;
}

