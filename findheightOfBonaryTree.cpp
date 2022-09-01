#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        ;
        left = NULL;
        right = NULL;
    }
};

int findHeight(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);

    return max(left_height, right_height) + 1;
}

// int calculateDiameter(Node* root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }

//     int lheight = findHeight(root->left);
//     int rheight = findHeight(root->right);
//     int currDiameter = lheight + rheight +  1;

//     int leftDiameter = calculateDiameter(root->left);
//     int rightDiameter = calculateDiameter(root->right);

//     return max(currDiameter, max(leftDiameter,rightDiameter));
// }

int calculateDiameter(Node* root, int *height)
{
    if(root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0 , rh = 0;
    int leftDiameter = calculateDiameter(root->left,&lh);
    int rightDiameter = calculateDiameter(root->right,&rh);

    int curr = lh + rh + 1;
    *height = max(lh,rh)+1;

    return max(curr,max(lh,rh));
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
    cout << findHeight(root) << endl;
    int height = 0;
    cout<<calculateDiameter(root,&height) << endl;
    return 0;
}