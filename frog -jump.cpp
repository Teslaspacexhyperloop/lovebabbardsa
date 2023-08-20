
// coding ninjas
#include <bits/stdc++.h>
#define MOD 1000000007
int rec(int n, vector<int> &heights)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return abs(heights[0] - heights[1]);
    }
    int left = abs(heights[n] - heights[n - 1]) + rec(n - 1, heights);
    int right = 0;

    right = abs(heights[n] - heights[n - 2]) + rec(n - 2, heights);

    return min(left, right);
}

int mem(int n, vector<int> &heights, vector<int> &dp)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return abs(heights[0] - heights[1]);
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = abs(heights[n] - heights[n - 1]) + mem(n - 1, heights, dp);
    int right = 0;

    right = abs(heights[n] - heights[n - 2]) + mem(n - 2, heights, dp);

    dp[n] = min(left, right);
    return dp[n];
}

int tab(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);

    for (int i = 2; i < n; i++)
    {
        int left = abs(heights[i] - heights[i - 1]) + dp[i - 1];

        int right = abs(heights[i] - heights[i - 2]) + dp[i - 2];
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}
int frogJump(int n, vector<int> &heights)
{
    //    int ans=rec(n-1,heights);

    // vector<int>dp(n,-1);
    //    int ans1=mem(n-1,heights,dp);
    int ans2 = tab(n, heights);
    return ans2;
}