
// GFG

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;

        // base case
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> topnode;      // pehla int horizontal distance 2nd int node->data
        queue<pair<Node *, int>> q; // yha pe int horizontal distance
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *frontnode = temp.first;
            int hd = temp.second;
            // if one value is present for horizontal distance do nothing

            topnode[hd] = frontnode->data;

            if (frontnode->left)
                q.push(make_pair(frontnode->left, hd - 1));
            if (frontnode->right)
                q.push(make_pair(frontnode->right, hd + 1));
        }
        for (auto i : topnode)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};