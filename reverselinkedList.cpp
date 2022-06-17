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

/***INSERTING A NODE AT TAIL***/
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
/***INSERTING A NODE AT HEAD***/
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

/***SEARCHING A NODE IN A LINKED LIST***/
bool search(node *&head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void deleteNode(node *head, int key)
{
    node *temp = head;
    while (temp->next->data != key)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

/****REVERSING THE LINKED LIST USING ITERATIVE MEATHOD****/
/*node *reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *nextptr;

    while (curr != NULL)
    {
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
    }
    // head=prev;

    return prev;
}*/

/****REVERSING THE LINKED LIST USING THE RECURSIVE MEATHOD****/
node* reverseRecursive(node* &head)
{
    if(head == NULL || head->next==NULL)
    {
        return head;
    }

    node* newHead= reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newHead;
}


/***DISPLAYING A LINKED LIST***/
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n"
         << endl;
}

int main()
{
    node *head = NULL;
    node *newhead = NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // display(head);
    while (1)
    {
        int n, data, ch, key, del;
        cout << "\n1.InsertAtStart\n2.InsertAtTail\n3.Display\n4.Search\n5.delete\n6.Reverse the linked list\n7.Exit\n"
             << endl;
        cout << "Enter your choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter value for node: ";
            cin >> data;
            insertAtHead(head, data);
            break;
        case 2:
            cout << "\nEnter value for node: ";
            cin >> data;
            insertAtTail(head, data);
            break;
        case 3:
            display(head);
            break;
        case 4:
            cout << "\nEnter the element you want to search: ";
            cin >> key;
            cout << search(head, key);
            break;
        case 5:
            cout << "\n Enter the element you want to delete: ";
            cin >> del;
            deleteNode(head, del);
            break;
        case 6:
            cout << "\nReversed linked list is : ";
            newhead = reverseRecursive(head); // we have created new node to store head pf our reversed linked list
            display(newhead);
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Invalid choice\n"
                 << endl;
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