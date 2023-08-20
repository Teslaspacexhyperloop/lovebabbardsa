
// GFG

// function Template for C++

// Function to reverse the queue.
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            s.push(front);
        }

        while (!s.empty())
        {
            int num = s.top();
            s.pop();
            q.push(num);
        }
        return q;
    }
};