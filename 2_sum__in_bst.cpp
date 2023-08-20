

#include <bits/stdc++.h>
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
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
***************/
void inorder(BinaryTreeNode<int> *root, vector<int> &inodr)
{
    if (root == NULL)
        return;

    inorder(root->left, inodr);
    inodr.push_back(root->data);
    inorder(root->right, inodr);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    // Write your code here
    vector<int> inodr;
    inorder(root, inodr);
    int i = 0;
    int j = inodr.size() - 1;
    while (i < j)
    {
        int sum = inodr[i] + inodr[j];
        if (sum == target)
        {
            return true;
        }
        if (sum > target)
        {
            j--;
        }
        if (sum < target)
        {
            i++;
        }
    }
    return false;
}