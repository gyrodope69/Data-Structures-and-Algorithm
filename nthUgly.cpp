#include <bits/stdc++.h>
using namespace std;

struct ll
{
    int data;
    ll *next;

    ll(int val)
    {
        data = val;
        next = NULL;
    }
};

struct dll
{
    int data;
    dll *next;
    dll *prev;

    dll(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(ll *&head1, int val)
{
    ll *node = new ll(val);
    if (head1 == NULL)
    {
        head1 = node;
        return;
    }
    head1 = node;
    node->next = head1;
}

void getDeletenode(dll *head2, ll *&head1)
{
    dll *temp = head2;
    int data = head2->data;
    head2 = head2->next;
    head2->prev = NULL;
    delete temp;
    insertAtHead(head1, data);
    // return data;
}
void insertAtHeadForDll(dll *&head2, int data)
{
    dll *node = new dll(data);
    node->next = head2;
    if (head2 != NULL)
    {
        head2->prev = node;
    }
    head2 = node;
}

void insertingInSortedWay(dll *&head2, int data)
{
    dll *node = new dll(data);
    if (head2 == NULL)
    {
        insertAtHeadForDll(head2, data);
        return;
    }
    dll *temp = head2;
    while (temp != NULL)
    {
        if (temp->data > data)
        {
            node->next = temp;
            node->prev = temp->prev;
            temp->prev = node;
        }
        else if (temp->data <= data)
        {
            temp->next = node;
            node->next = temp->next;
            node->prev = temp;
        }
    }
}
int nthUgly(int n, dll *&head2, ll *&head1)
{
    int count = 1;
    insertingInSortedWay(head2, 1);
    for (int i = 1; i < n; i++)
    {
        int twoMultiple = 2 * head1->data;
        int threeMultiple = 3 * head1->data;
        int fivemultiple = 5 * head1->data;
        insertingInSortedWay(head2, twoMultiple);
        insertingInSortedWay(head2, threeMultiple);
        insertingInSortedWay(head2, fivemultiple);
        getDeletenode(head2, head1);
    }
    return head1->data;
}

int main()
{
    int n;
    cin >> n;
    ll *head1 = NULL;
    dll *head2 = NULL;
    cout << nthUgly(n, head2, head1);
    return 0;
}