

// gfg

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
public:
    void rec(Node *root, int h, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (ans.size() == h)
        {
            ans.push_back(root->data);
        }
        rec(root->right, h + 1, ans);
        rec(root->left, h + 1, ans);
    }
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        rec(root, 0, ans);
        return ans;
    }
};