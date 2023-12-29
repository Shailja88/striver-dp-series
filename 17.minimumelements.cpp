#include <bits/stdc++.h> 
int fun(vector<int>&nums,int target,int i){
    if(i==0){
        if(target%nums[i]==0)return target/nums[i];
        return 1e9;
    }
///pick not pick
int notpick=fun(nums,target,i-1);
int pick =1e9;
if(nums[i]<=target)
  pick=1+fun(nums,target-nums[i],i);
  return min(pick,notpick);


}
int minimumElements(vector<int> &num, int x)
{
     //Don't waste a single second 
     //recursion  tc=o(>>>>>2^n) sc =O(x);
      int ans=fun(num,x,num.size()-1);
 if(ans>=1e9)return -1;
 return ans;
}


//memoization
#include <bits/stdc++.h> 
int fun(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
    if(i==0){
        if(target%nums[i]==0)return target/nums[i];
        return 1e9;
    }
///pick not pick
if(dp[i][target]!=-1)return dp[i][target];
int notpick=fun(nums,target,i-1,dp);
int pick =1e9;
if(nums[i]<=target)
  pick=1+fun(nums,target-nums[i],i,dp);
  return dp[i][target]= min(pick,notpick);


}
int minimumElements(vector<int> &num, int x)
{
     //Don't waste a single second 
     //recursion  tc=o(n*x) sc =O(n*x+x);
     int n=num.size();
     vector<vector<int>>dp(n,vector<int>(x+1,-1));
      int ans=fun(num,x,n-1,dp);
 if(ans>=1e9)return -1;
 return ans;
}


///tabulation
#include <bits/stdc++.h> 

int minimumElements(vector<int> &num, int target) {
  // Don't waste a single second
  // TABULATION  tc=o(n*x) sc =O(n*x);
  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(target + 1, 0));

//BASE CASE
    for(int  t=0;t<=target;t++){
      if(t%num[0]==0)dp[0][t]=t/num[0];
      else
      dp[0][t]=1e9;
     for(int i=1;i<n;i++){
          for(int t=0;t<=target;t++){     
            int notpick=dp[i-1][t];
            int pick =1e9;
            if(num[i]<=t)
             pick=1+dp[i][t-num[i]];
             
           
            dp[i][t]=min(pick,notpick);
          }
       }
    }
return  (dp[n-1][target]==1e9)?-1:dp[n-1][target];
}
//space optimization
#include <bits/stdc++.h> 

int minimumElements(vector<int> &num, int target) {
  // Don't waste a single second
  // TABULATION  tc=o(n*x) sc =O(x);
  int n = num.size();
 vector<int> prev(target + 1, 0),curr(target+1,0);

//BASE CASE
 for (int t = 0; t <= target; t++) {
   if (t % num[0] == 0)
     prev[t] = t / num[0];
   else
     prev[t] = 1e9;
 }
     for(int i=1;i<n;i++){
          for(int t=0;t<=target;t++){     
            int notpick=prev[t];
            int pick =1e9;
            if(num[i]<=t)
             pick=1+curr[t-num[i]];
             
           
            curr[t]=min(pick,notpick);
          }
          prev=curr;
       }
    
return  (prev[target]==1e9)?-1:prev[target];
}
