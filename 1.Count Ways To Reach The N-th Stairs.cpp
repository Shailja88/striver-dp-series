#include <bits/stdc++.h> 
#define MOD 1000000007
//memoization ----top down
int dp[1000000]={0};
int countDistinctWays(int nStairs) {
 if(nStairs==0 || nStairs==1)return 1;
 if(dp[nStairs]!=0)return dp[nStairs];
 return dp[nStairs]=(countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2))%MOD;
}

//tabulation --bottom up
#include <bits/stdc++.h> 
#define MOD 1000000007
int countDistinctWays(int nStairs) {
    //  Write your code here.
    //tabulation method
    vector<long long>dp(nStairs+1,0);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=nStairs;i++){
        dp[i]=(dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
    }
    return  (dp[nStairs]);
}
