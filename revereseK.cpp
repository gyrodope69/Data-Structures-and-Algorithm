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

node *reverseK(node *&head, int key)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;

    while (currptr != NULL && count < key)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reverseK(nextptr, key);
    }

    return prevptr;
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
    node *head = NULL;
    node *keyHead = NULL;
    int ch, data, key;
    while (1)
    {
        cout << "\n1.Insert a node\n2.reverse a k node\n3.Display\n4.exit\n";
        cout << "Enter a choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the data for node : ";
            cin >> data;
            insert(head, data);
            break;
        case 2:
            cout << "\nEnter the key : ";
            cin >> key;
            keyHead = reverseK(head, key);
            display(keyHead);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\nInvalid choice!!!\n";
            break;
        }
    }
    return 0;
}