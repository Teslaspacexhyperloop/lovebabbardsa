
// gfg

class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    pair<int, int> diameterfast(Node *root)
    {
        if (root == NULL)
        {
            pair<int, int> p1 = make_pair(0, 0);
            return p1;
        }

        pair<int, int> left = diameterfast(root->left);
        pair<int, int> right = diameterfast(root->right);

        int leftd = left.first;
        int rightd = right.first;
        int lefth = left.second;
        int righth = right.second;

        int op3 = lefth + righth + 1;

        int dia = max(leftd, max(rightd, op3));
        pair<int, int> p1 = make_pair(dia, max(lefth, righth) + 1);
        return p1;
    }
    int diameter(Node *root)
    {
        return diameterfast(root).first;
    }
};