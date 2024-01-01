#include<bits/stdc++.h>
using namespace std;
   int lcs(string &s1,int n,string &s2,int m,vector<vector<int>>&dp){
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s1[i-1]==s2[j-1])
               dp[i][j]=1+dp[i-1][j-1];
               else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
       return dp[n][m];
   }
   int canYouMake(string &s1, string &s2){
    // Write your code here.
      int n=s1.size();
      int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  
    return m+n-2*lcs(s1,n,s2,m,dp);
}
