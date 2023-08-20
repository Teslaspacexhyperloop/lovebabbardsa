// coding ninjas

// no of path to reach from 0,0 to n-1,n-1

#include <bits/stdc++.h>
int f(int m, int n, int row, int col, vector<vector<int>> &dp)
{
    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (row == 0 && col == 0)
    {
        return 1;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    else
    {
        int left = f(m, n, row, col - 1, dp);
        int up = f(m, n, row - 1, col, dp);
        dp[row][col] = left + up;
        return dp[row][col];
    }
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m, n, m - 1, n - 1, dp);
}