

// coding ninjas

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int succ = -1;
    TreeNode *ans = NULL;
    findnode(root, ans, key);
    if (ans == NULL)
    {
        pair<int, int> p1 = make_pair(pred, succ);
        return p1;
    }
    TreeNode *temp = root;
    while (temp->data != key && temp != NULL)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // predecessor ke liye ek left fir right right
    TreeNode *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    /// successor ke liye ek right fir left left
    TreeNode *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int, int> p1 = make_pair(pred, succ);
    return p1;
}