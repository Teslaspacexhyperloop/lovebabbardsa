

coding ninjas

#include <bits/stdc++.h>

    void
    solve(string &str, vector<string> &output, string ans, int ind, int n)
{
    if (ind > n)
    {
        output.push_back(ans);
        return;
    }

    solve(str, output, ans, ind + 1, n);

    ans.push_back(str[ind]);
    solve(str, output, ans, ind + 1, n);
}
vector<string> subsequences(string str)
{

    vector<string> output;
    string ans;
    solve(str, output, ans, 0, str.length() - 1);
    return output;
}
