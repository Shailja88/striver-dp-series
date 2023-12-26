//memoization SC+O(m)+O(m*n*n)
//TC=O(m*n*n)*9
#include <bits/stdc++.h> 
int fun(vector<vector<int>> &grid,int i,int j1,int j2,int n,int m,vector<vector<vector<int>>>&dp)
{
        //out of boundry
        if(j1<0 || j1>=n || j2<0 || j2>=n)return -1e8;
        if(i==m-1){
            if(j1==j2)return grid[i][j1];
            else 
            return grid[i][j1]+grid[i][j2];
        }
      //express everything in term of i j1, j2 
      //explore all the paths 
      //return max
      if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
      int maxi=-1e8;
      for(int dj1=-1;dj1<=1;dj1++){
          int po=0;
          for(int dj2=-1;dj2<=1;dj2++){
                  if(j1==j2) 
                  po=grid[i][j1];
                  else 
                  po=grid[i][j1]+grid[i][j2];
                 maxi=max(maxi,(po+fun(grid,i+1,j1+dj1,j2+dj2,n,m,dp)));
              }
      }

return dp[i][j1][j2]=maxi;



}
int maximumChocolates(int m, int n, vector<vector<int>> &grid) {
    // recursion

    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    return fun(grid,0,0,n-1,n,m,dp);//m ==rows ,,n==column
}




#include <bits/stdc++.h> 

int maximumChocolates(int m, int n, vector<vector<int>> &grid) {
       vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
 //base case khatm
    for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){
            if(j1==j2)dp[m-1][j1][j2]=grid[m-1][j1];
            else
            dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
        }
    }
////loops lgao
    for(int i=m-2;i>=0;i--){
     for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){

              int maxi=-1e8;
             for(int dj1=-1;dj1<=1;dj1++){
             
              for(int dj2=-1;dj2<=1;dj2++){
                   int po=0;
                  if(j1==j2) 
                  po=grid[i][j1];
                  else 
                  po=grid[i][j1]+grid[i][j2];
                 if(j1+dj1>=0&& j1+dj1<n && j2+dj2>=0 &&j2+dj2<n)
                 po+=dp[i+1][j1+dj1][j2+dj2];
                 else 
                 po+=-1e8;
                 maxi=max(maxi,po);
              }
      }
      
dp[i][j1][j2]=maxi;

        }
    }
}
return dp[0][0][n-1];
}



//space optimization 


#include <bits/stdc++.h> 

int maximumChocolates(int m, int n, vector<vector<int>> &grid) {
       vector<vector<int>>dp(n,vector<int>(n,0)),curr(n,vector<int>(n,0));
 //base case khatm
    for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){
            if(j1==j2)dp[j1][j2]=grid[m-1][j1];
            else
            dp[j1][j2]=grid[m-1][j1]+grid[m-1][j2];
        }
    }
////loops lgao
    for(int i=m-2;i>=0;i--){
     for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){

              int maxi=-1e8;
             for(int dj1=-1;dj1<=1;dj1++){
             
              for(int dj2=-1;dj2<=1;dj2++){
                   int po=0;
                  if(j1==j2) 
                  po=grid[i][j1];
                  else 
                  po=grid[i][j1]+grid[i][j2];
                 if(j1+dj1>=0&& j1+dj1<n && j2+dj2>=0 &&j2+dj2<n)
                 po+=dp[j1+dj1][j2+dj2];
                 else 
                 po+=-1e8;
                 maxi=max(maxi,po);
              }
      }
      
curr[j1][j2]=maxi;

        }
    }
    dp=curr;
}
return dp[0][n-1];
}
