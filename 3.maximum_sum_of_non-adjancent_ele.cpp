//TC=O(N) SC=O(N) ....MEMOIZATION 
#include <bits/stdc++.h> 
using namespace std;
int solve(vector<int>&nums,int ind,vector<int>&dp){
    if(dp[ind]!=-1)return dp[ind];
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    int r1= nums[ind]+solve(nums,ind-2,dp);
    int r2= solve(nums,ind-1,dp);
    return dp[ind]= max(r1,r2);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    //using recursion 
    if(nums.size()==1)return nums[0];
    vector<int>dp(nums.size(),-1);
    solve(nums,nums.size()-1,dp);
   return dp[nums.size()-1];
}

///TABULATION 
#include <bits/stdc++.h> 
using namespace std;
//tc=O(n)
//sc=o(n) ...no auxiliary stack space 
int maximumNonAdjacentSum(vector<int> &nums){
    // using tabulation
    int n=nums.size();
    vector<int>dp(n,0);
      dp[0]=nums[0];
      int take=0,nontake=0;
    for (int i = 1; i < n; i++) {
        take=nums[i];
        if(i>1)take+=dp[i-2];
        nontake=dp[i-1];
        dp[i]=max(take,nontake);
         
    }
    return dp[n-1];
}

//space optimation 
#include <bits/stdc++.h> 
using namespace std;
//tc=O(n)
//sc=o(1) ...no auxiliary stack space + no extra space
int maximumNonAdjacentSum(vector<int> &nums){
    // using tabulation
    int n=nums.size();
    int prev1=nums[0],prev2=0;
       for (int i = 1; i < n; i++) {
        int take=nums[i]+prev2;
         int nontake=prev1;
        prev2=prev1;
        prev1=max(take,nontake);
         
    }
    return prev1;
}
