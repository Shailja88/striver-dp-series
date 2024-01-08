#include <bits/stdc++.h> 
int fun(vector<int>&a,int i,int j,vector<vector<int>>&dp){
   //base case
 if(i>j)return  0;
 if(dp[i][j]!=-1)return dp[i][j];
   //pick 
   int maxi=INT_MIN;
   for(int k=i;k<=j;k++)
 { 
    int left = (i == k) ? 0 : fun(a, i, k - 1,dp);
        int right = (j == k) ? 0 : fun(a, k + 1, j,dp);
        int pick = a[i - 1] * a[k] * a[j + 1] + left + right;
        maxi = max(maxi, pick);
    }
return dp[i][j]= maxi;
}
int maxCoins(vector<int> &a) {
a.insert(a.begin(), 1);
a.push_back(1);
int n = a.size();
vector<vector<int>>dp(n,vector<int>(n,-1));
return fun(a, 1, n - 2,dp);
}

///tabulation
#include <bits/stdc++.h> 

int maxCoins(vector<int> &a) {
a.insert(a.begin(), 1);
a.push_back(1);
int n = a.size();
vector<vector<int>>dp(n,vector<int>(n,0));
for(int i=n-1;i>=1;i--){
	   int maxi=INT_MIN;
	for(int j=i;j<n-1;j++){
		  for(int k=i;k<=j;k++)
 { 
        int left = (i == k) ? 0 : dp[i][k-1]; 
        int right = (j == k) ? 0 : dp[k + 1][j];
        int pick = a[i - 1] * a[k] * a[j + 1] + left + right;
        maxi = max(maxi, pick);
    }

 dp[i][j]= maxi;
	}
}
return dp [1][n-2];
}
