GFG;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (M[i][j] == 1)
        { // i know j then i is not celebrity
            s.push(j);
        }
        else
        { // if i dont know j then j cant be a celebrity
            s.push(i);
        }
    }

    int ans = s.top();
    bool rowcheck = false;
    int cr = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
        {
            cr++;
        }
    }
    if (cr == n)
        rowcheck = true;

    int cc = 0;
    bool colcheck = false;
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
        {
            cc++;
        }
    }
    if (cc == n - 1)
        colcheck = true;

    if (rowcheck && colcheck)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}