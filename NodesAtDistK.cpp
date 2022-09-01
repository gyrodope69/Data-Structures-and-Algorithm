#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Case 1
void printSubTree(Node* root, int k )
{
    if(root == NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data << " ";
        return;
    }
    if(k>0)
    {
        printSubTree(root->left,k-1);
        printSubTree(root->right,k-1);
    }
}

// Case 2
int  printNodeAtK(Node *root, Node* target , int k)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root == target)
    {
        printSubTree(root, k);
        return 0;
    }
    int dl = printNodeAtK(root->left, target, k);
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubTree(root->right,k-dl-2);
        }
        return dl+1;
    }
    int dr = printNodeAtK(root->right, target, k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubTree(root->left,k-dr-2);
        }
        return dr+1;
    }

    return -1;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    printNodeAtK(root,root->left,1);
    return 0;
}