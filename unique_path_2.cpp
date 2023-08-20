

// on a grid there is obstacle also with mat[i][j]==-1

// calculate no of unique path from 0,0 to n-1,n-1

#include <bits/stdc++.h>
#define MOD 1000000007

int rec(int n, int m, vector<vector<int>> &mat)
{
    if (n == 0 && m == 0)
        return 1;

    if (n < 0 || m < 0)
    {
        return 0;
    }

    if (mat[n][m] == -1)
    {
        return 0;
    }

    int left = rec(n, m - 1, mat);
    int up = rec(n - 1, m, mat);

    return left + up;
}

int mem(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return 1;

    if (n < 0 || m < 0)
    {
        return 0;
    }

    if (mat[n][m] == -1)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    int left = mem(n, m - 1, mat, dp);
    int up = mem(n - 1, m, mat, dp);

    return dp[n][m] = (left + up) % MOD;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // return rec(n-1,m-1,mat);

    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return mem(n-1,m-1,mat,dp);

    // tabulation
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else if (mat[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else
            {
                int left = 0;
                if (j - 1 >= 0)
                    left += dp[i][j - 1];

                int up = 0;
                if (i - 1 >= 0)
                    up += dp[i - 1][j];

                dp[i][j] = (left + up) % MOD;
            }
        }
    }
    return dp[n - 1][m - 1];
}