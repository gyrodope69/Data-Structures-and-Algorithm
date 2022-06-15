#include<bits/stdc++.h>

using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    node* n= new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val)
{
    node *n= new node(val);
    n->next=head;
    head=n;
}

bool search(node* &head,int key)
{
    node *temp = head;
    while(temp->next!=NULL)
    {
        if(temp->data==key)
          return true;
        temp=temp->next;
    }
    return false;
}

void display(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n"<<endl;
} 

int main()
{
    node* head=NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // display(head);
    while(1){
    int n,data,ch,key;
    cout<<"\n1.InsertAtStart\n2.InsertAtTail\n3.Display\n4.Search\n"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch){
        case 1: cout<<"\nEnter value for node: ";
                cin>>data;
                insertAtHead(head,data);
                break;
        case 2: cout<<"\nEnter value for node: ";
                cin>>data;
                insertAtTail(head,data);
                break;
        case 3 : display(head); 
                break;
        case 4 : cout<<"\nEnter the element you want to search: ";
                 cin>>key;
                 cout<<search(head,key);
                 break;
        default: cout<<"Invalid choice\n"<<endl;
                 break;
    }
    // cout<<"Enter number of nodes: ";
    // cin>>n;
    // while(n--) {
    //     cin>>data;
    //     insertAtTail(head,data);
    // }
    // insertAtHead(head,69);
    // display(head);   
    }

   return 0;
}