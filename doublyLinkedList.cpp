#include <bits/stdc++.h>
using namespace std;

/***CLASS OF NODE***/
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

/***FUNCTION TO INSERT NODE AT HEAD***/
void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

/***FUNCTION TO INSERT NODE AT END***/
void insertAtEnd(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

/***FUNCTION TO DELETE NODE AT HEAD***/
void deleteAtHead(node *&head)
{
    node *toDelete;
    node *temp = head;
    head = head->next;
    head->prev = NULL;

    delete temp;
}

/***FUNCTION TO DELETE NODE EXCEPT HEAD***/
void deleteNode(node *&head, int pos)
{
    node *temp = head;
    int count = 1;
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

/***FUNCTION TO DISPLAY***/
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
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    display(head);
    insertAthead(head, 5);
    display(head);
    deleteNode(head, 1);
    display(head);
    return 0;
}