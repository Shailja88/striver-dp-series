#include<bits/stdc++.h>
using namespace std;
int fun(string &s1,int i1,string &s2,int i2,vector<vector<int>>&dp){
       //base case
       if(i1<0)
       return  i2+1;
       if(i2<0)return i1+1;
       if(dp[i1][i2]!=-1)return  dp[i1][i2];
   ///if matching
   if(s1[i1]==s2[i2])
    return dp[i1][i2]= fun(s1,i1-1,s2,i2-1,dp);
  
    int Delete=1+fun(s1,i1-1,s2,i2,dp);
    int Replace=1+fun(s1,i1-1,s2,i2-1,dp);
    int Insert=1+fun(s1,i1,s2,i2-1,dp);
    return dp[i1][i2]=min(Delete,min(Replace,Insert));
}
int editDistance(string str1, string str2)
{
    /*Delete 
      Replace
      Insert
      TC=O(n*m) SC=O(n*m ) + O( n+m)
    */
     int n=str1.size(),m=str2.size();
     vector<vector<int>>dp(n,vector<int>(m,-1));
     return fun(str1,n-1,str2,m-1,dp);
}


//tabulation

#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1, string s2)
{
    /*Delete 
      Replace
      Insert
    */

     int n=s1.size(),m=s2.size();
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     for(int i=0;i<=n;i++){
         dp[i][0]=i;
     }
     for(int j=0;j<=m;j++){
         dp[0][j]=j;
     }
     for(int i1=1;i1<=n;i1++){
       for(int i2=1;i2<=m;i2++){
         
         if(s1[i1-1]==s2[i2-1])
     dp[i1][i2]= dp[i1-1][i2-1];
         else {
     int Delete = 1 + dp[i1 - 1][i2];
     int Replace = 1 + dp[i1 - 1][i2 - 1];
     int Insert = 1 + dp[i1][i2 - 1];
     dp[i1][i2] = min(Delete, min(Replace, Insert));
         }
       }
     }
     return dp[n][m];
}


//space optimization
#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1, string s2)
{
    /*Delete 
      Replace
      Insert
    */

     int n=s1.size(),m=s2.size();

    vector<int>prev(m+1,0),curr(m+1,0);
     for(int j=0;j<=m;j++){
         prev[j]=j;
     }
     for(int i1=1;i1<=n;i1++){
       curr[0]=i1;
       for(int i2=1;i2<=m;i2++){
         
         if(s1[i1-1]==s2[i2-1])
     curr[i2]= prev[i2-1];
         else {
     int Delete = 1 + prev[i2];
     int Replace = 1 + prev[i2 - 1];
     int Insert = 1 + curr[i2 - 1];
     curr[i2] = min(Delete, min(Replace, Insert));
         }
       }
       prev=curr;
     }
     return prev[m];
}
