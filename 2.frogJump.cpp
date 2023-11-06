////tc=o(n) sc=o(n) memoization top down
#include <bits/stdc++.h> 
int f(int ind,vector<int>&heights,vector<int>&dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=f(ind-1,heights,dp)+abs(heights[ind-1]-heights[ind]);
    int right=INT_MAX;
    if(ind>1) right=f(ind-2,heights,dp)+abs(heights[ind-2]-heights[ind]);
    return dp[ind]= min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,-1);
    return f(n-1,heights,dp);

}

//tabulation --bottom up tc=o(n) sc =o(n)
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int ls=dp[i-1]+abs(heights[i-1]-heights[i]);
        int rs=INT_MAX;
        if(i>1) rs=dp[i-2]+abs(heights[i-2]-heights[i]);
        dp[i]=min(rs,ls);
    }
    return dp[n-1];

}

//space optimization
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,0);
    int cur=0;
      int prev1=0,prev2=0;
    for(int i=1;i<n;i++){
        int ls=prev1+abs(heights[i-1]-heights[i]);
        int rs=INT_MAX;
        if(i>1) rs=prev2+abs(heights[i-2]-heights[i]);
        cur=min(rs,ls);
        prev2=prev1;
        prev1=cur;
    }
    return prev1;

}
