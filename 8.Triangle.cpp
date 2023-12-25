/*Memoization Tc=O(2^n)
SC=O(n^2)+O(n*n)
*/

#include <bits/stdc++.h> 
int find(vector<vector<int>>&triangle,int n,int i,int j,vector<vector<int>>&dp){
   if(i==n-1)return triangle[i][j];
   if(dp[i][j]!=-1)return dp[i][j];
   int  down=triangle[i][j]+find(triangle,n,i+1,j,dp);
   int dig=triangle[i][j]+find(triangle,n,i+1,j+1,dp);
   return dp[i][j]=min(down,dig);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	//starting from 0;
	vector<vector<int>>dp(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
           dp[i].push_back(-1);
		}
	}
	return find(triangle,n,0,0,dp);
}



#include <bits/stdc++.h> 

int minimumPathSum(vector<vector<int>>& triangle, int n){
	/*
 Tabulation 
 Tc=O(n*n)
	Sc=O(n*n)*/
	vector<vector<int>>dp(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
           dp[i].push_back(-1);
		}
	}
    for(int j=0;j<n;j++)dp[n-1][j]=triangle[n-1][j];
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
            int down=triangle[i][j]+dp[i+1][j];
			int dig=triangle[i][j]+dp[i+1][j+1];
			dp[i][j]=min(down,dig);
	}
	}
	return dp[0][0];
}




/*Space optimization 
TC=O(n*n)
SC=O(n)
*/



#include <bits/stdc++.h> 

int minimumPathSum(vector<vector<int>>& triangle, int n){
	/*Tc=O(n*n)
	Sc=O(n)*/
	vector<int>front(n,0),curr(n,0);
	
    for(int j=0;j<n;j++)front[j]=triangle[n-1][j];
	for(int i=n-2;i>=0;i--){
		
		for(int j=i;j>=0;j--){
            int down=triangle[i][j]+front[j];
			int dig=triangle[i][j]+front[j+1];
		     curr[j]=min(down,dig);
		}
		front=curr;
	}
	return front[0];
}
