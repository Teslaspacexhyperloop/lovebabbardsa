

#include <bits/stdc++.h>
int rec(int arr[], int i, int prev_ind, int n, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }

    if (dp[i][prev_ind + 1] != -1)
        return dp[i][prev_ind + 1];

    int pick = 0;
    if (prev_ind == -1 || arr[prev_ind] < arr[i])
    {
        pick = 1 + rec(arr, i + 1, i, n, dp);
    }

    int nonpick = rec(arr, i + 1, prev_ind, n, dp);

    return dp[i][prev_ind + 1] = max(pick, nonpick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return rec(arr,0,-1,n,dp);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev_ind = i - 1; prev_ind >= -1; prev_ind--)
        {

            int pick = 0;
            if (prev_ind == -1 || arr[prev_ind] < arr[i])
            { // yha pemprev ind -1 h to error nhi aayega kya
                pick = 1 + dp[i + 1][i + 1];
            }

            int nonpick = dp[i + 1][prev_ind + 1];

            dp[i][prev_ind + 1] = max(pick, nonpick);
        }
    }
    return dp[0][0];
}
