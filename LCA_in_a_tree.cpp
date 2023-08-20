
// GFg
class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *solve(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }
        Node *left = solve(root->left, n1, n2);
        Node *right = solve(root->right, n1, n2);

        if (left == NULL && right != NULL)
        {
            return right;
        }
        if (left != NULL && right == NULL)
        {
            return left;
        }
        if (left != NULL && right != NULL)
        {
            return root;
        }
    }
    Node *lca(Node *root, int n1, int n2)
    {
        Node *ans = solve(root, n1, n2);
        return ans;
    }