//without recursion TC=O(min(n-1,m-1)) SC=O(1)
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// without recursion
	long long ans=1;
	int r=m-1+n-1;
	int x=min(m-1,n-1);
	for(int i=1;i<=x;i++){
		ans=ans*(r--)/i;
	} 
return ans;
}       

//with recursion
#include <bits/stdc++.h> 
int fun(int i, int j){
	if(i==0 && j==0)return 1;
	if(i<0 || j<0)return 0;
	int up=fun(i-1,j);
	int left=fun(i,j-1);
	return up+left;
}
int uniquePaths(int m, int n) {
	// recursion TC+O(2^(m*n))
	//SC=O(n)
	return fun(m-1,n-1);
}

//memoization 
#include <bits/stdc++.h> 
int fun(int i, int j,vector<vector<int>>&dp){
	if(i==0 && j==0)return 1;
	if(i<0 || j<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int up=fun(i-1,j,dp);
	int left=fun(i,j-1,dp);
	return dp[i][j]= up+left;
}
int uniquePaths(int m, int n) {
	// recursion TC+O((m*n)) + memoization 
	//SC=O(m*n)+O(m-1+n-1);
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return fun(m-1,n-1,dp);
}///

//tabulation
#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
	// recursion TC+O((m*n)) + tabulation 
	//SC=O(m*n);
	vector<vector<int>>dp(m,vector<int>(n,0));
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0)
			dp[0][0]=1;
			else{

				int left=0,up=0;
			  if(i>0) up=	dp[i-1][j];
			  if(j>0) left=	dp[i][j-1];
				dp[i][j]=up+left;
			}
		}
	}
	return dp[m-1][n-1];
}


///space optimization
//TC=O(m*n)
//SC=O(2n)
#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
	// recursion TC+O((m*n)) + tabulation 
	//SC=O(m*n);
	vector<int>prev(n,0);
	
	for(int i=0;i<m;i++){
        vector<int>curr(n,0);
		for(int j=0;j<n;j++){
			if(i==0 && j==0)
			curr[j]=1;
			else{

				int left=0,up=0;
			  if(i>0) up=	prev[j];
			  if(j>0) left=	curr[j-1];
				curr[j]=up+left;
			}
		}
        prev=curr;
	}
	return prev[n-1];
}
