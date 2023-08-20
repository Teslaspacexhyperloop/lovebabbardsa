

// coding ninjas

bool isBST(BinaryTreeNode<int> *root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBST(root->left, mini, root->data);
    bool right = isBST(root->right, root->data, maxi);

    if (left && right && (root->data > mini && root->data < maxi))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}