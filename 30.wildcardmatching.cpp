//memoization
#include<bits/stdc++.h>
using namespace std;
bool fun(string & s1, int i,string &s2,int j,vector<vector<int>>&dp){
//base case
if(i<0 && j<0)return true;
 else if(i<0)return false;
 else if(j<0){
    bool flag=true;
    for(int r=i;r>=0;r--){
       if(s1[r]!='*')flag= false;
    }
    return flag;
 }
if(dp[i][j]!=-1)return dp[i][j];
if(s1[i]==s2[j]||s1[i]=='?')
return dp[i][j]= fun(s1,i-1,s2,j-1,dp);

else if(s1[i]=='*'){
return dp[i][j]=fun(s1,i-1,s2,j,dp)+fun(s1,i,s2,j-1,dp);
}
else return  dp[i][j]=false;
}
bool wildcardMatching(string pattern, string text)
{
   //TC=O(n*m) SC=O(n*m)+O(N+M)
   int n=pattern.size();
   int m=text.size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
   return fun(pattern,n-1,text,m-1,dp);
}

//tabulation method
#include<bits/stdc++.h>
using namespace std;

bool wildcardMatching(string s1, string s2)
{
   //TC=O(n*m) SC=O(n*m)+O(N+M)
   int n=s1.size();
   int m=s2.size();
   vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
   dp[0][0]=1;
   for(int i=1;i<=m;i++)
    dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {  
       bool flag=true;
     for(int i1=1;i1<=i;i1++)
       {
          if(s1[i1-1]!='*') 
         { 
           flag=false;
          break;
         }
       }
      dp[i][0]=flag;
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
          if(s1[i-1]==s2[j-1]||s1[i-1]=='?')
        dp[i][j]= dp[i-1][j-1];

         else if(s1[i-1]=='*'){
          dp[i][j]=dp[i-1][j]||dp[i][j-1];
          }
     else  dp[i][j]=false;
}
       }
  return dp[n][m];
}
//space optimization
#include<bits/stdc++.h>
using namespace std;

bool wildcardMatching(string s1, string s2)
{
   //TC=O(n*m) SC=O(m)
   int n=s1.size();
   int m=s2.size();
   vector<bool>dp(m+1,0),curr(m+1,0);
   dp[0]=1;
   for(int i=1;i<=m;i++)
    dp[i]=0;
     for(int i=1;i<=n;i++){
       bool flag=true;
       for(int i1=1;i1<=i;i1++){
           if(s1[i1-1]!='*')
           {flag=false;
           break;
           }
       }
       curr[0]=flag;
       for(int j=1;j<=m;j++){
          if(s1[i-1]==s2[j-1]||s1[i-1]=='?')
        curr[j]= dp[j-1];

         else if(s1[i-1]=='*'){
          curr[j]=dp[j]||curr[j-1];
          }
     else  curr[j]=false;
}
dp=curr;
       }
    
   return dp[m];
}

