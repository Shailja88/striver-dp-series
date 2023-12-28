#include <bits/stdc++.h> 
bool fun(vector<int>&arr,int target,int i,int sum,int n){
  if(sum==target)return true;
  if(i>=n)return false;
 bool x=false;
 if(sum<target) x= fun(arr,target,i+1,sum+arr[i],n);//take
 bool y= fun(arr,target,i+1,sum,n);//not take
   return x|y;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // TC=O(2^n) SC=O(N);  recursion
    return fun(arr,k,0,0,n);
}

//memoization
#include <bits/stdc++.h> 
bool fun(vector<int>&arr,int target,int i,int sum,int n,vector<vector<int>>&dp){
  if(sum==target)return true;
  if(sum>target|| i>=n)return false;
  if(dp[i][sum]!=-1)return dp[i][sum];
 bool x=false;
 if(sum<target) x= fun(arr,target,i+1,sum+arr[i],n,dp);//take
 bool y= fun(arr,target,i+1,sum,n,dp);//not take
   return dp[i][sum]=x|y;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // TC=O(n*k) SC=O(N*k);

    vector<vector<int>>dp(n+1,vector<int>((k+1),-1));
    return fun(arr,k,0,0,n,dp);
}


///tabulaltion
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // TC=O(n*k) SC=O(N*K) TABULATION
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
     for(int i=0;i<n;i++){
       dp[i][0]=true;
     }
   dp[0][arr[0]]=true;
   for(int i=1;i<n;i++){
     for(int j=1;j<=k;j++){
           bool x=dp[i-1][j];
           bool y=false;
           if(j>=arr[i])
                 y=dp[i-1][j-arr[i]];
         dp[i][j]=x|y;


     }
   }

    return  dp[n-1][k];
}

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // TC=O(n*k) SC=O(K) TABULATION
    vector<bool>prev(k+1,0),curr(k+1);
      prev[0]=curr[0]=true;
      prev[arr[0]]=true;
   for(int i=1;i<n;i++){
     for(int j=1;j<=k;j++){
           bool x=prev[j];
           bool y=false;
           if(j>=arr[i])
                 y=prev[j-arr[i]];
         curr[j]=x|y;


     }
     prev=curr;
   }

    return prev[k];
}
