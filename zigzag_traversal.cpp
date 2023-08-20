// GFG

// User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        // make a queue
        bool lefttoright = true; // yeh btayega left to right jana h ki right to left
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {

            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++)
            {
                Node *frontnode = q.front();
                q.pop();

                // normal flow that is left to right or abrupt flow that is right or left
                int index = lefttoright ? i : size - i - 1;
                ans[index] = frontnode->data;

                if (frontnode->left)
                {
                    q.push(frontnode->left);
                }

                if (frontnode->right)
                {
                    q.push(frontnode->right);
                }
                // direction change
            }
            lefttoright = !lefttoright;
            for (auto i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};