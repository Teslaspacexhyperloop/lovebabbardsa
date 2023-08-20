
// gfg

// Function to check if two trees are identical.
bool isIdentical(Node *r1, Node *r2)
{

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool op3;
    if (r1->data == r2->data)
    {
        op3 = true;
    }
    else
    {
        op3 = false;
    }
    return left && right && op3;
}