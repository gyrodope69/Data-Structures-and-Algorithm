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
        left = NULL;
        right = NULL;
    }
};

bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}
/*APPROACH 1*/
int lowestCommonAncestor1(Node *root, int n1, int n2)  // Time complexity for this is O(n)
{
    vector<int> path1;
    vector<int> path2;
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() && pc < path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc - 1];
}

/*APPROACH 2*/
Node* LCA(Node* root , int n1 , int n2)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node*  left = LCA(root->left , n1 , n2);
    Node* right = LCA(root->right , n1 , n2);

    if(left && right) return root;
    if(left!=NULL) return left;
    if(right!=NULL) return right;
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
    int n1 = 6;
    int n2 = 7;
    // cout <<"The lowest common ancestor of "<<n1<<" and "<<n2<<" is : "<<lowestCommonAncestor1(root, n1, n2) << endl;
    Node* ans = LCA(root , n1 , n2);
    cout <<"The lowest common ancestor of "<<n1<<" and "<<n2<<" is : "<<ans->data << endl;
    return 0;
}