#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int fun(vector<int>&arr, int sum,int i,vector<vector<int>>&dp){

  if (i == 0) {

    if(sum==0 && arr[0]==0) return 2;

    if(sum==arr[0] || sum==0 ) return 1;

    return 0;

  }
if(dp[i][sum]!=-1)return  dp[i][sum];
//not pick

long long notpick=fun(arr,sum,i-1,dp);
long long pick=0;
if(sum>=arr[i])pick=fun(arr,sum-arr[i],i-1,dp);
return dp[i][sum]=( pick%mod+notpick%mod)%mod;


}
int findWays(vector<int>& arr, int k)
{
	// recursion
  
    vector<vector<int>>dp(arr.size(),vector<int>(k+1,-1));
    return fun(arr,k,arr.size()-1,dp)%mod;


}
