#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* next;

    node(int val){
        data = val;
        next=NULL;
    }

};

void insert(node *&head, int val)
{
    node *temp = head;
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Function to make cycle
void makeCycle(node* &head , int pos)
{
    node* temp = head;
    node* startNode;
    int count = 0;
    while(temp->next != NULL)
    {
        if(count==pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

// Function to create cycle
bool detectCycle(node* head)
{
   node* fast = head;
   node*slow = head;

   while(fast!=NULL && fast->next != NULL)
   {
     slow = slow->next;
     fast = fast->next->next;

     if(slow==fast)
        return true;
   }
   return 0;
}

void removeCycle(node* &head){
    node* fast=head;
    node* slow=head;
    while(slow!=fast)
    {
        slow= slow->next;
        fast=fast->next->next;
    }
    
    fast = head;
    while(slow->next!=fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next=NULL;
}
void display(node *head)
{
    node *temp = head;
    if(head==NULL)
      cout<<""<<endl;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node* head = NULL;
    int ch,data,pos;
    while(1)
    {
        cout<<"\n1.Insert node\n2.Check cycle\n3.Display\n4.Make cycle\n5.Remove cycle\n6.Exit\n";
        cout<<"Enter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter the data : ";
                    cin>>data;
                    insert(head,data);
                    break;
            case 2: cout<<detectCycle(head);
                    break;
            case 3 : display(head); 
                     break;
            
            case 4 : cout<<"Enter the position to make cycle : ";
                     cin>>pos;
                     makeCycle(head,pos);
                     break;
            case 5 : removeCycle(head); 
                     break;
            case 6 : exit(0); break;

            default : cout<<"\nInvalid choice\n";
                      break;
        }             
    }
    
    return 0;
}