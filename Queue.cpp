// ARRAY IMPLEMENTATION OF QUEUES //
#include <bits/stdc++.h>
using namespace std;
#define n 100

/*
Operations :
1. Enqueue(x)
2. Dequeue;
3.peek()
4.empty()
*/

class Queue
{
    int *arr;
    int front, back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void Enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "\nQueue is full\n";
            return;
        }
        back++;
        arr[back] = x;

        if (front = -1)
        {
            front++;
        }
    }

    void Dequeue()
    {
        if (front == -1)
        {
            cout << "\nQueue is empty\n";
            return;
        }
        else if (front > back)
        {
            cout << "\nQueue is empty\n";
            return;
        }
        front++;
    }

    int peek()
    {
        if (front > back || front == -1)
        {
            return -1;
        }
        return arr[front];
    }

    bool Empty()
    {
        if (front > back || front == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    cout<<q.peek()<<endl;
    q.Dequeue();
    q.Dequeue();
    cout<<q.peek()<<endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    cout<<q.peek()<<endl;
    cout<<q.Empty()<<endl;
    q.Dequeue();
    return 0;
}