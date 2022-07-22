#include <bits/stdc++.h>
using namespace std;

// class Node{

//     public:
//     int data;
//      Node* left;
//      Node* right;

//     Node(int val)
//    {
//      data = val;
//      left = NULL;
//      right = NULL;
//    }
// };

// int search(int inorder[] , int start , int end , int curr)
// {
//     for(int i = start ; i<= end ; i++)
//     {
//         if(inorder[i] == curr)
//          {
//             return i;
//          }
//     }
//     return -1;
// }

// Node* buildTree(int preorder[] , int inorder[] , int start , int end)
// {
//     if(start > end)
//     {
//         return NULL;
//     }

//     static int idx = 0;
//     int curr = preorder[idx];
//     idx++;
//     Node* node = new Node(curr);
//     if(start == end)
//     {
//         return node;
//     }
//     int pos = search(inorder, start , end , curr);
//     node->left = buildTree(preorder, inorder , start , pos-1);
//     node->right = buildTree(preorder , inorder , pos+1 , end);

//     return node;
// }

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int searchInOrder(int InOrder[], int start, int end, int curr)
{
    for (int j = start; j <= end; j++)
    {
        if (InOrder[j] == curr)
        {             // if current element in inOrder
            return j; // return it's index
        }
    }
    return -1; // which is not possible.
}
node *BuildTree(int InOrder[], int PreOrder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int i = 0;
    int curr = PreOrder[i];      // 1. select the current element
    node *root = new node(curr); // 1(2).create a new node
    i++;                         // 2. Increment the index
    if (start == end)
    {
        return root; // means only 1 node in our inorder.
    }
    int pos = searchInOrder(InOrder, start, end, curr);
    // 3. search for its position in InOrder
    root->left = BuildTree(InOrder, PreOrder, start, pos - 1);
    // 4. Build using the left subarray of InOrder
    root->right = BuildTree(InOrder, PreOrder, pos + 1, end);
    // 5. Build using the right subarray of InOrder
    return root;
}

void inorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 3, 4, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    node *root = BuildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}