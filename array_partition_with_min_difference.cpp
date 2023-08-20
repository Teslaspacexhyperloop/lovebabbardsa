// divide array into two half in such a way that minimum absolute difference between sum of each half is minimum

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int k = sum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool nottake = dp[i - 1][j];
            bool take = false;
            if (j >= arr[i])
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = take | nottake;
        }
    }
    int mini = 1e9;
    for (int i = 0; i <= k; i++)
    {
        if (dp[n - 1][i] == true)
        {
            mini = min(mini, abs((sum - i) - i));
        }
    }
    return mini;
}
