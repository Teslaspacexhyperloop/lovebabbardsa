/ coding ninjas

#include <bits/stdc++.h>
    int
    rec(int n, vector<int> &nums)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
        return nums[0];

    int take = nums[n] + rec(n - 2, nums);
    int notTake = 0 + rec(n - 1, nums);
    return max(take, notTake);
}
int mem(int n, vector<int> &nums, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
        return nums[0];
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int take = nums[n] + mem(n - 2, nums, dp);
    int notTake = 0 + mem(n - 1, nums, dp);
    dp[n] = max(take, notTake);
    return dp[n];
}

int tab(int n, vector<int> &nums)
{
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int take = 0;

        take = nums[i];
        if (i > 1)
        {
            take += dp[i - 2];
        }
        int notTake = 0 + dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = rec(n - 1, nums);
    int ans1 = mem(n - 1, nums, dp);
    int ans2 = tab(n, nums);
    return ans2;
}