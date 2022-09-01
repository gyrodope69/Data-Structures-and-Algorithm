/*LINKED LIST IMPLEMENTATION OF QUEUES*/

#include <bits/stdc++.h>
using namespace std;

/*We are created a class for node*/
class node{
    public:
    int data;
    node* next;
         
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

/*we are created class for function which will form queue*/
class Queue{
    node* front;
    node* back;

    public:
     Queue()
     {
        front = NULL;
        back = NULL;
     }  

     void enqueue(int x)
     {
        node* n = new node(x);
        if(front == NULL)
        {
            back=n;
            front = n;
            return;
        }
         back->next=n;
         back=n;
     }

     void dequeue()
     {
        if(front == NULL)
        {
            cout<<"Queue is empty!"<<endl;
            return;
        }
        node* todelete;
        todelete = front;
        front= front->next;
        delete todelete;
     }

     int peek()
     {
        if(front==NULL)
        {
            // cout<<"Queue is empty!"<<endl;
            return -1;
        }
         
         return front->data;
     }

     bool isEmpty()
     {
        if(front==NULL)
        {
            return true;
        }

        return false;
     } 
};

int main()
{
    Queue q;  // creating the object for class queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    cout<<q.peek()<<endl;
    return 0;
}