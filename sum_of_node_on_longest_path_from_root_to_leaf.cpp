// gfg

void solve(Node *root, int len, int &maxlen, int sum, int &maxsum)
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxsum = sum;
            maxlen = len;
        }
        if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    solve(root->left, len + 1, maxlen, sum + root->data, maxsum);
    solve(root->right, len + 1, maxlen, sum + root->data, maxsum);
}
int sumOfLongRootToLeafPath(Node *root)
{
    // code here
    int maxsum = 0;
    int maxlen = 0;

    solve(root, 0, maxlen, 0, maxsum);
    return maxsum;
}