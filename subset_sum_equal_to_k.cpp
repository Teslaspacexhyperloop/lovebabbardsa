
// coding ninjas

#include <bits/stdc++.h>
bool rec(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;

    if (k < 0)
    {
        return false;
    }

    if (i == 0)
    {
        if (k == arr[0])
            return true;

        return false;
    }
    if (dp[i][k] != -1)
        return dp[i][k];

    bool take = rec(i - 1, k - arr[i], arr, dp);
    bool nottake = rec(i - 1, k, arr, dp);

    return dp[i][k] = take | nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return rec(n - 1, k, arr, dp);

    //   vector<vector<bool>>dp(n,vector<bool>(k+1,0));

    //     for(int i=0;i<n;i++){
    //         dp[i][0]=true;
    //     }

    //     dp[0][arr[0]]=true;

    // for(int i=1;i<n;i++){
    //     for(int j=1;j<=k;j++){
    //       bool nottake=dp[i-1][j];
    //       bool take=false;
    //       if(j>=arr[i]){
    //           take=dp[i-1][j-arr[i]];
    //       }
    //       dp[i][j]=take | nottake;
    //     }

    // }

    // return dp[n-1][k];
}