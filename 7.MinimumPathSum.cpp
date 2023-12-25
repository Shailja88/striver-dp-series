//memoization
#include <bits/stdc++.h> 
int fun(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
   
     if(i==0 && j==0)return grid[0][0];
       if(i<0 || j<0)return INT_MAX;
     if (dp[i][j] != -1)
         return dp[i][j];
       int up=INT_MAX,left=INT_MAX;
      if(i>0)  up = grid[i][j] + fun(grid, i - 1, j, dp);
      if(j>0)  left = grid[i][j] + fun(grid, i, j - 1, dp);
       return dp[i][j] = min(up, left);
   
}
int minSumPath(vector<vector<int>> &grid) {
    /*tc=O(n*m)
      sc=O(n*m)+O(m+n)
*/

    int i=grid.size();
    int j=grid[0].size();
      vector<vector<int>>dp(i,vector<int>(j,-1));
    return fun(grid,i-1,j-1,dp);
}

//tabulation
#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n=grid.size();
    int m=grid[0].size();
      vector<vector<int>>dp(n,vector<int>(m,0));
    
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(i==0 && j==0) dp[i][j]=grid[i][j];
      else {

        int up = grid[i][j], left = grid[i][j];
        if (i > 0)
          up = up + dp[i - 1][j];
        else
          up = INT_MAX;
        if (j > 0)
          left = left + dp[i][j - 1];
        else
          left = INT_MAX;
        dp[i][j] = min(up, left);
      }
    }
  }
  return dp[n-1][m-1];
}


//space optimization
#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n=grid.size();
    int m=grid[0].size();
      vector<int>prev(m,0);
    
  for(int i=0;i<n;i++){
    vector<int>curr(m,0);
    for(int j=0;j<m;j++){
      if(i==0 && j==0) curr[j]=grid[i][j];
      else {

        int up = grid[i][j], left = grid[i][j];
        if (i > 0)
          up = up + prev[j];
        else
          up = INT_MAX;
        if (j > 0)
          left = left +curr[j - 1];
        else
          left = INT_MAX;
        curr[j] = min(up, left);
      }
    }
    prev=curr;
  }
  return prev[m-1];
}
