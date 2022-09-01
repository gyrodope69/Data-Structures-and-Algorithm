#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *skip;

    Node(int val)
    {
        data = val;
        next = NULL;
        skip = NULL;
    }
};

void insertAthead(Node *&head, int data)
{
    Node *node = new Node(data);
    node->next = head;
    // Node* temp = head->next;
    if (head != NULL)
    {
        node->skip = head->next;
        // temp->next = NULL;
    }
    else
    {
        node->skip = NULL;
    }
    head = node;
}

void insertAtend(Node *&head, int data)
{
    if (head == NULL)
    {
        insertAthead(head, data);
        return;
    }
    Node *node = new Node(data);
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->next == NULL)
        {
            temp->skip = node;
        }
        temp = temp->next;
    }
    // temp->skip = node;
    temp->next = node;
}

void findAndInsert(Node *&head, int k, int data)
{
    Node *temp = head;
    Node *node = new Node(data);
    if (head->data == k)
    {
        insertAthead(head, data);
    }
    while (temp != NULL)
    {
        if (temp->next->next != NULL && temp->next->next->data == k)
        {
            cout<<temp->data<<"\n";
            /*For inserting before the element*/
            node->skip = temp->next->skip;
            temp->next->skip = temp->skip;
            temp->skip = node;
            node->next = temp->next->next;
            temp->next->next = node;
            
            //  node->skip = temp->next->next->skip;
            //  node->next = temp->next->next;
            //  temp->next->next->skip = temp->next->skip;
            //  temp->next->skip = node;
            //  temp->next->next = node;
             return;
        }
        else if (temp->next != NULL && temp->next->data == k)
        {
            // cout<<temp->data<<"\n";
            node->skip = temp->skip;
            temp->skip = temp->next;
            node->next = temp->next;
            temp->next = node;
            return;
        }
        temp = temp->next;
    }

}

void print(Node *head)
{
    Node *temp = head;
    Node *temp2 = head->next;
    Node *temp3 = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->skip;
    }
    cout << "NULL\n";
    while (temp2 != NULL)
    {
        cout << temp2->data << "->";
        temp2 = temp2->skip;
    }
    cout << "NULL\n";
    cout << "Linked list: ";
    while (temp3 != NULL)
    {
        cout << temp3->data << "->";
        temp3 = temp3->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = NULL;
    insertAtend(head, 5);
    insertAtend(head, 6);
    insertAtend(head, 7);
    insertAtend(head, 8);
    insertAtend(head, 9);
    // insertAthead(head, 1);
    // insertAthead(head, 2);
    // insertAthead(head, 3);
    // insertAthead(head, 4);
    print(head);
    findAndInsert(head, 6, 13); // inserting between the element
    print(head);
    return 0;
}