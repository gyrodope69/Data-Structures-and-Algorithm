#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int maxSumNode(Node* root , int& ans)
{
 if(root == NULL)
 {
    return 0;
 }
 int left = maxSumNode(root->left,ans);
 int right = maxSumNode(root->right,ans);
 int nodeMax = max(max(root->data+left,root->data+right), max(root->data,root->data+left+right));
 ans = max(ans,nodeMax);
 int single = max(root->data,max(root->data+left,root->data+right));
 return single;

}
int maxSum(Node* root)
{
    int ans = INT_MIN;
    maxSumNode(root,ans);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<maxSum(root)<<endl;
    return 0;
}