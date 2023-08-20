
// gfg

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    void traversalLeft(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return;
        }
        ans.push_back(root->data);
        if (root->left)
            traversalLeft(root->left, ans);
        else
        {
            traversalLeft(root->right, ans);
        }
    }

    void traverseLeaf(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traversalRight(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return;
        }

        if (root->right)
            traversalRight(root->right, ans);
        else
        {
            traversalRight(root->left, ans);
        }
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);

        // left part print
        traversalLeft(root->left, ans);

        // left leaf node
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        // right part node
        traversalRight(root->right, ans);

        return ans;
    }
};