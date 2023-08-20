// coding ninjas

#include <bits/stdc++.h>
int rec(vector<vector<int>> &grid, int r, int c)
{
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }
    if (r < 0 || c < 0)
    {
        return 1e9;
    }

    int left = grid[r][c] + rec(grid, r, c - 1);
    int right = grid[r][c] + rec(grid, r - 1, c);

    return min(left, right);
}

int mem(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &dp)
{
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }
    if (r < 0 || c < 0)
    {
        return 1e9;
    }
    if (dp[r][c] != -1)
        return dp[r][c];

    int left = grid[r][c] + mem(grid, r, c - 1, dp);
    int right = grid[r][c] + mem(grid, r - 1, c, dp);

    return dp[r][c] = min(left, right);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    // int ans=rec(grid,row-1,col-1);

    // int ans=mem(grid,row-1,col-1,dp);
    // return ans;

    dp[0][0] = grid[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else
            {
                int left = grid[i][j];
                if (j - 1 >= 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;

                int right = grid[i][j];
                if (i - 1 >= 0)
                    right += dp[i - 1][j];
                else
                {
                    right += 1e9;
                }

                dp[i][j] = min(left, right);
            }
        }
    }
    return dp[row - 1][col - 1];
}