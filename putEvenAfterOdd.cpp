#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void evenAfterOdd(node* &head)
{
   node* odd = head;  // 1->2->3->4->5  so first odd will be head
   node* even=head->next; // Even pointer will start form head->next
   node* evenStart=even;
   while(odd->next!=NULL && even->next!= NULL)
   {
    odd->next=even->next;
    odd=odd->next;
    even->next=odd->next;
    even=even->next;
   }
   odd->next=evenStart;
   if(odd->next!=NULL)
   {
    even->next=NULL;
   }

}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    evenAfterOdd(head);
    display(head);
    return 0;
}