#include<bits/stdc++.h>
//recursion+memoization
using namespace std;
int fun(int i,int j,vector<vector<int>>&maze,vector<vector<int>>&dp){
    if(i>=0 && j>=0 && maze[i][j]==-1)return 0;
    if(i==0&& j==0)return 1;
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    long long up = fun(i - 1, j, maze, dp) % (1000000007);
    long long left = fun(i, j - 1, maze, dp) % (1000000007);

    return dp[i][j] = (up + left) % (1000000007);
    
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return fun(n-1,m-1,mat,dp);
}
//tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int n=obstacleGrid.size();
      int m=obstacleGrid[0].size();
       vector<vector<int>>dp(n,vector<int>(m,0));
      for(int i=0;i<n;i++)
      {
       for(int j=0;j<m;j++){
          if(obstacleGrid[i][j]==1)dp[i][j]=0;
         else if(i==0 && j==0)dp[i][j]=1;
          else{
            int up =0,left=0;
            if(i>0)up=dp[i-1][j];
            if(j>0)left=dp[i][j-1];
            dp[i][j]=up+left;
          }
          }
      }   
      return dp[n-1][m-1];
    }
};
//space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int n=obstacleGrid.size();
      int m=obstacleGrid[0].size();
       vector<int>prev(m,0);
      for(int i=0;i<n;i++)
      {
          vector<int>curr(m,0);
       for(int j=0;j<m;j++){
          if(obstacleGrid[i][j]==1)curr[j]=0;
         else if(i==0 && j==0)curr[j]=1;
          else{
            int up =0,left=0;
            if(i>0)up=prev[j];
            if(j>0)left=curr[j-1];
            curr[j]=up+left;
          }
          }
          prev=curr;
      }   
      return prev[m-1];
    }
};
