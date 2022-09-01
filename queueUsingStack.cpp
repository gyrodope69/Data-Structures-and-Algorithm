/*IMPLEMENTING QUEUE USING STACK AND FUNCTION CALL STACK (using recursive call)*/
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> st;

public:
    void Enqueue(int x)
    {
        st.push(x);
    }

    int Dequeue()
    {
        if (st.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int x = st.top();
        st.pop();
        if (st.empty())
        {
            return x;
        }

        int item = Dequeue();   // Getting to the last element in stack st(through recursion) and pushing to stack *st
        st.push(x);

        return item;
    }

    bool empty()
    {
        if(st.empty())
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
    cout<<q.Dequeue()<<endl;
    q.Enqueue(5);
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    
    return 0;
}