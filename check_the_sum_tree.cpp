

// gfg

class Solution
{
public:
    pair<bool, int> sumtree(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p1 = make_pair(true, 0);
            return p1;
        }
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p1 = make_pair(true, root->data);
            return p1;
        }
        pair<bool, int> left = sumtree(root->left);
        pair<bool, int> right = sumtree(root->right);

        bool op1 = left.first;
        bool op2 = right.first;
        int leftd = left.second;
        int rightd = right.second;
        bool op3;
        if ((leftd + rightd) == root->data)
        {
            op3 = true;
        }
        else
        {
            op3 = false;
        }

        bool ans = op1 && op2 && op3;
        pair<bool, int> p1 = make_pair(ans, leftd + rightd + root->data);
        return p1;
    }
    bool isSumTree(Node *root)
    {
        return sumtree(root).first;
    }
};