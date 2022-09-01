#include<bits/stdc++.h>
using namespace std;


// we will not be using extra stack 
// we will reverse a stack using reccursion
// we will be inserting at bottom
void insertAtBottom(stack<int> &st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int topp = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topp);
}

void reverse(stack<int> &st){
    if(st.empty())
    {
        return;
    }
    int element = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,element);
}
int main() {
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    reverse(st);
    while(!st.empty()){
      cout<<st.top()<<" ";
      st.pop();
    }
    return 0;
}