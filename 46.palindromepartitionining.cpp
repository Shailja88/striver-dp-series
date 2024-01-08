#include <bits/stdc++.h> 
//without dp
bool isPalindrome(int i,int j,string s){
    while(i<j)
    {if(s[i++]!=s[j--])return false;
    }
    return true;
}
 int func(string &s,int ind,int n,vector<int>&dp){
   if(ind==n)return 0;
   if(dp[ind]!=-1)return dp[ind];
   int mincost=INT_MAX;
   for(int j=ind;j<n;j++){
       if(isPalindrome(ind,j,s)){
       int cost=1+func(s,j+1,n,dp);
        mincost=min(mincost,cost);
       }
   }
return dp[ind]=mincost;
 }
int palindromePartitioning(string str) {
  int n=str.size();
    // Write your code here
    vector<int>dp(n,-1);
  return func(str,0,n,dp)-1;


}
