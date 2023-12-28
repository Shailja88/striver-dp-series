#include <bits/stdc++.h> 
int fun(vector<int>&weight,vector<int>&value,int i,int W,vector<vector<int>>&dp){
  if (i == 0) {
	  if(weight[i]<=W){
		  return value[i];
	  }
	  else 
	  return 0;
  }
if(dp[i][W]!=-1)return dp[i][W];

// take
int take = INT_MIN;
if (W >= weight[i])
  take = value[i] + fun(weight, value, i - 1, W - weight[i],dp);
// nottake
int notake = fun(weight, value, i - 1, W,dp);
return dp[i][W]= max(take, notake);

// TC=o(n*w),sc=o(n*w+n);

}
int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
	 vector<vector<int>>dp(n,vector<int>(W+1,-1));
	return fun(weight,value,weight.size()-1,W,dp);
	// Write your code here
}


#include <bits/stdc++.h> 
// TC=o(n*w),sc=o(n*w);


int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
	 vector<vector<int>>dp(n,vector<int>(W+1,0));
     for(int i=weight[0];i<=W;i++){
		 dp[0][i]=value[0];
	 }

	  for(int i=1;i<n;i++){
		  for(int wt=0;wt<=W;wt++){
           int take=INT_MIN;
		   if(wt>=weight[i])
		   take=value[i]+dp[i-1][wt-weight[i]];
		   int notake=dp[i-1][wt];
		   dp[i][wt]=max(take,notake);

		  }
	  }
return dp[n-1][W];
	
}

///space opptimization
#include <bits/stdc++.h> 


// TC=o(n*w),sc=o(w);


int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
	 vector<int>dp(W+1,0),curr(W+1);
     for(int i=weight[0];i<=W;i++){
		dp[i]=value[0];
	 }

	  for(int i=1;i<n;i++){
		  for(int wt=0;wt<=W;wt++){
           int take=INT_MIN;
		   if(wt>=weight[i])
		   take=value[i]+dp[wt-weight[i]];
		   int notake=dp[wt];
		   curr[wt]=max(take,notake);


		  }
		  dp=curr;
	  }
	return dp[W];
	// Write your code here
}


#include <bits/stdc++.h> 
// TC=o(n*w),sc=o(w);
int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
	 vector<int>dp(W+1,0);
     for(int i=weight[0];i<=W;i++){
		dp[i]=value[0];
	 }
	  for(int i=1;i<n;i++){
		  for(int wt=W;wt>=0;wt--){
           int take=INT_MIN;
		   if(wt>=weight[i])
		   take=value[i]+dp[wt-weight[i]];
		   int notake=dp[wt];
		   dp[wt]=max(take,notake);
  }
		
	  }
  
	return dp[W];
	// Write your code here
}
