
// GFG

string FirstNonRepeating(string A)
{
    int n = A.length();
    queue<char> q;
    string ans = "";
    ans = ans + A[0];
    q.push(A[0]);
    map<char, int> m;
    m[A[0]]++;
    for (int i = 1; i < n; i++)
    {
        m[A[i]]++;
        q.push(A[i]);
        while (!q.empty() && m[q.front()] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            ans += '#';
        }
        else
        {
            ans += q.front();
        }
    }
    return ans;
}
