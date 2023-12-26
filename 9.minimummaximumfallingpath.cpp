
//TLE
#include <bits/stdc++.h> 
int fun(vector<vector<int>> &matrix,int i,int j){
    //bound cases
if(j<0 || j>=matrix[0].size())return -1e9;
if(i==0)return matrix[i][j];
int up=matrix[i][j]+fun(matrix,i-1,j);
int ld=matrix[i][j]+fun(matrix,i-1,j-1);
int rd=matrix[i][j]+fun(matrix,i-1,j+1);
return max(up,max(ld,rd));

}
int getMaxPathSum(vector<vector<int>> &matrix)
{//recursion  tc=O(3^n) SC=O(n)
   int n=matrix.size();
   int m=matrix[0].size();
   int maxi=-1e9;
for(int j=0;j<m;j++){
   maxi=max(maxi,fun(matrix,n-1,j));

}
return maxi;
}

#include <bits/stdc++.h> 
int fun(vector<vector<int>> &matrix,int i,int j,vector<vector<int>>&dp){
    //bound cases
if(j<0 || j>=matrix[0].size())return -1e9;
if(i==0)return matrix[i][j];
if(dp[i][j]!=-1)return dp[i][j];
int up=matrix[i][j]+fun(matrix,i-1,j,dp);
int ld=matrix[i][j]+fun(matrix,i-1,j-1,dp);
int rd=matrix[i][j]+fun(matrix,i-1,j+1,dp);
return dp[i][j]=max(up,max(ld,rd));

}
int getMaxPathSum(vector<vector<int>> &matrix)
{//memoization  tc=O(m*n) SC=O(n*m+n)
   int n=matrix.size();
   int m=matrix[0].size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
   int maxi=-1e9;
for(int j=0;j<m;j++){
   maxi=max(maxi,fun(matrix,n-1,j,dp));

}
return maxi;
}
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{//Tabulation  tc=O(m*n) SC=O(n*m)
   int n=matrix.size();
   int m=matrix[0].size();
   vector<vector<int>>dp(n,vector<int>(m,0));
   for(int j=0;j<m;j++)
   dp[0][j]=matrix[0][j];
   for(int i=1;i<n;i++){
       for(int j=0;j<m;j++){
         
         int up=matrix[i][j]+dp[i-1][j];
         int  ld=matrix[i][j];
         if(j-1>=0)ld+=dp[i-1][j-1];
         else 
         ld+=-1e8;
        int rd=matrix[i][j];
        if(j+1<m)
        rd+=dp[i-1][j+1];
        else
        rd+=-1e8;
       dp[i][j]=max(up,max(ld,rd));

       }
   }
   int maxi=-1e8;
  for(int i=0;i<m;i++){
      maxi=max(maxi,dp[n-1][i]);
  }
return maxi;
}
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{//Tabulation+space optimization  tc=O(m*n) SC=O(m)
   int n=matrix.size();
   int m=matrix[0].size();
   vector<int>prev(m,0),curr(m,0);
   for(int j=0;j<m;j++)
   prev[j]=matrix[0][j];
   for(int i=1;i<n;i++){
       
       for(int j=0;j<m;j++){
         
         int up=matrix[i][j]+prev[j];
         int  ld=matrix[i][j];
         if(j-1>=0)ld+=prev[j-1];
         else 
         ld+=-1e8;
        int rd=matrix[i][j];
        if(j+1<m)
        rd+=prev[j+1];
        else
        rd+=-1e8;
       curr[j]=max(up,max(ld,rd));

       }
       prev=curr;
   }
   int maxi=-1e8;
  for(int i=0;i<m;i++){
      maxi=max(maxi,prev[i]);
  }
return maxi;
}
