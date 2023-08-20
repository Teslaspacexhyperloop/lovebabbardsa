
// coding ninjas
#include <bits/stdc++.h>
#define MOD 1000000007
// long rec(int *denominations, int i, int value){
//     if(value==0){
//         return 1;
//     }
//     if(value<0){
//         return 0;
//     }

//     if(i==0){
//         if(value%denominations[i]==0){
//             return 1;
//         }
//         return 0;
//     }

//     int take=rec(denominations,i,value-denominations[i]);
//     int nottake=rec(denominations,i-1,value);

//     return take+nottake;
// }

long mem(int *denominations, int i, int value, vector<vector<long>> &dp)
{
    if (value == 0)
    {
        return 1;
    }
    if (value < 0)
    {
        return 0;
    }

    if (i == 0)
    {
        if (value % denominations[i] == 0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[i][value] != -1)
    {
        return dp[i][value];
    }

    long take = mem(denominations, i, value - denominations[i], dp);
    long nottake = mem(denominations, i - 1, value, dp);

    return dp[i][value] = (take + nottake);
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    // return rec(denominations,n-1,value);
    //  return mem(denominations,n-1,value,dp);

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= value; i++)
    {
        if (i % denominations[0] == 0)
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            long take = 0;
            if (j - denominations[i] >= 0)
                take += dp[i][j - denominations[i]];
            long nottake = dp[i - 1][j];

            dp[i][j] = (take + nottake);
        }
    }

    return dp[n - 1][value];
}