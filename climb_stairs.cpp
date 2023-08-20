

#include <bits/stdc++.h>
#define MOD 1000000007
// int solve(int nStairs,int i){//i refers to my current atair
//     if(i==nStairs){
//         return 1;
//     }
//     if(i>nStairs){
//                return 0;}
//     return (solve(nStairs,i+1)+solve(nStairs,i+2))%MOD;
// }

// int rec(int n,vector<int>&dp){
//         // n th sidhi pe ya to ek sidhi piche se aaye h ya to phir do sidhi peeche se aae h
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return 1;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     dp[n]=(rec(n-1,dp)+rec(n-2,dp))%MOD;
//  return dp[n];
// }

int countDistinctWays(int nStairs)
{

    // vector<int>dp(nStairs+1,-1);
    // int ans=rec(nStairs,dp);
    // return ans;
    // vector<int>dp(nStairs+1,-1);
    // dp[0]=1;

    // for(int i=1;i<=nStairs;i++){
    //     int left=dp[i-1];
    //     int right=0;
    //     if(i-2>=0){
    //          right=dp[i-2];
    //     }
    //     dp[i]=(left+right)%MOD;

    // }

    int prev2 = 0;
    int prev1 = 1;
    int ans = 1;
    for (int i = 1; i <= nStairs; i++)
    {
        ans = (prev2 + prev1) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}