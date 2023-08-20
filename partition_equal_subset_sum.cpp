// Q.divide array into two half such that sum of each half is equal
approach
    // find subset sum equal to =totalsum/2;

    bool
    subsetSumToK(int n, int k, vector<int> &arr)
{

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

    return dp[n - 1][k];
}
bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        return subsetSumToK(n, sum / 2, arr);
    }
}
