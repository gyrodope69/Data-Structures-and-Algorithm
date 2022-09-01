#include <bits/stdc++.h>
using namespace std;

/***CLASS OF NODE***/
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

/***FUNCTION FOR INSERTING AT HEAD***/
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

/***FUNCTION FOR INSERTING AT END***/
void insertAtEnd(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

/***FUNCTION FOR DELETING AT END***/
void deleteAtEnd(node *&head)
{
    node *temp = head;
    node *todelete;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    todelete = temp->next;
    temp->next = head;
    delete todelete;
}

/***FUNCTION FOR DELETING AT HEAD***/
void deleteAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

/***FUNCTION FOR DELETION AT ANY POSITION***/
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *todelete;
    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    todelete = temp->next;
    temp->next = temp->next->next;
}

/***FUNCTION FOR DISPLAY***/
void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp->next != head);
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    display(head);
    insertAtHead(head, 6);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}