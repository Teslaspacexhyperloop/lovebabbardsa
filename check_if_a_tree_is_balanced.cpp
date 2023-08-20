

// GFG

class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    pair<int, int> isbalancefast(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = isbalancefast(root->left);
        pair<bool, int> right = isbalancefast(root->right);

        bool op1 = left.first;
        bool op2 = right.first;
        int lefth = left.second;
        int righth = right.second;
        bool op3;
        if (abs(lefth - righth) <= 1)
        {
            op3 = true;
        }
        else
        {
            op3 = false;
        }

        bool ans = op1 && op2 && op3;
        pair<bool, int> p1 = make_pair(ans, max(lefth, righth) + 1);
        return p1;
    }
    bool isBalanced(Node *root)
    {
        return isbalancefast(root).first;
    }
};