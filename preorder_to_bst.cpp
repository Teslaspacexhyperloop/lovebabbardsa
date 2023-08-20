

#include <bits/stdc++.h>
/*
    Following is the class structure of BinaryTreeNode class for referance:

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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
// we have preorder to inorder then built the tree
BinaryTreeNode<int> *inordertoBST(vector<int> &preorder, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = s + (e - s) / 2; //..mid element hmara head h
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[mid]);
    // recursion left subtree bna le aayega usko bs root->left sejod do
    root->left = inordertoBST(preorder, s, mid - 1);
    root->right = inordertoBST(preorder, mid + 1, e);

    return root;
}
BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    sort(preorder.begin(), preorder.end());
    int s = 0;
    int e = preorder.size() - 1;
    return inordertoBST(preorder, s, e);
}