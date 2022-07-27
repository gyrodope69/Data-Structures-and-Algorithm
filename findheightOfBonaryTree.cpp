#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
      data = val;;
      left = NULL;  
      right = NULL;
    }
};

int findHeight(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }

    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);

    return max(left_height, right_height)+1;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

     /*
            1
          /   \
         2     3
        / \   / \   
       4   5 6    7

    */
    cout<<findHeight(root)<<endl;
    return 0;
}