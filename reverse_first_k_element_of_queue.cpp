
// gfg

// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    // pehla 3 element stack me daal ke reverse kr liye
    stack<int> s;
    int n = q.size() - k;
    while (k != 0)
    {
        int val = q.front();
        q.pop();
        s.push(val);
        k--;
    }
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    for (int i = n - k; i > 0; i--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}