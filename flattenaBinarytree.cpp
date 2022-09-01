#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data ;
    Node* left;
    Node* right;

    Node(int val)
    {
      data = val;
      left = NULL;
      right = NULL;
    }
};


void flattenTree(Node* root)
{
    if(root == NULL || root->left == NULL && root->right == NULL) 
    {
        return;
    }
    if(root->left!=NULL)
    {
        flattenTree(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* temp2 = root->right;
        while(temp2->right!= NULL)
        {
            temp2 = temp2->right;
        }
        temp2->right  = temp;
    }

    flattenTree(root->right);
}

void inorder(struct Node* root)
{
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    flattenTree(root);
    inorder(root);
    return 0;
}