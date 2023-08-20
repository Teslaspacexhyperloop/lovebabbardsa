

// coding ninjas

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void find(BinaryTreeNode<int> *root, int &ind, int k, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    find(root->left, ind, k, ans);
    ind++;
    if (ind == k)
    {
        ans = root->data;
    }
    find(root->right, ind, k, ans);
}

int kthSmallest(BinaryTreeNode<int> *root, int k)
{

    int ans = -1;
    int ind = 0;
    find(root, ind, k, ans);
    return ans;
}