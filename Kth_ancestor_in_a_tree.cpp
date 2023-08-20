// GFG

// User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
Node *rec(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;
    if (root->data == node)
    {
        return root;
    }

    Node *left = rec(root->left, k, node);
    Node *right = rec(root->right, k, node);

    if (left != NULL)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            return root;
        }
        else
        {
            return left;
        }
    }
    else if (right != NULL)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            return root;
        }
        else
        {
            return right;
        }
    }
    else
    {
        return NULL;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = rec(root, k, node);
    if (ans->data == node)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}