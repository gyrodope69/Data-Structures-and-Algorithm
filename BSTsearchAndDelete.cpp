#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

Node* searchBST(Node* root , int key )
{
    if(root == NULL)
    {
        return root;
    }

    if(root->data == key)
    {
        return root;
    }

     if(root->data>key)
    {
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}
Node* deleteInBST(Node* &root , int key)
{
 
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    if( searchBST(root,5)==NULL)
    {
        cout<<"Key does not exist";
    }
    else
    {
        cout<<"Key exist";
    }
    // printInorder(root);

}