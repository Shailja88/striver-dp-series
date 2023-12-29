#include<bits/stdc++.h>
using namespace std;
int fun(int i,int w,vector<int>&profit,vector<int>&weight){
    if(i==0){
        return (int)(w/weight[0])*profit[0];    
    }
    int notake=fun(i-1,w,profit,weight);
    int take=INT_MIN;
    if(weight[i]<=w)
    take=profit[i]+fun(i,w-weight[i],profit,weight);
    
    return max(take,notake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // RECURSION. tc exponential and space compexity O(w)
 return fun(n-1,w,profit,weight);
}


#include<bits/stdc++.h>
using namespace std;
int fun(int i,int w,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){
    if(i==0){
        return (int)(w/weight[0])*profit[0];    
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int notake=fun(i-1,w,profit,weight,dp);
    int take=INT_MIN;
    if(weight[i]<=w)
    take=profit[i]+fun(i,w-weight[i],profit,weight,dp);
    
    return dp[i][w]= max(take,notake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // memoization. tcO(w*n) and space compexity O(w*n)
  vector<vector<int>>dp(n,vector<int>(w+1,-1));



 return fun(n-1,w,profit,weight,dp);
}

#include<bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // tabulation. tcO(w*n) and space compexity O(w*n)
  vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int wt=0;wt<=w;wt++){
        dp[0][wt]=(int)(wt/weight[0])*profit[0];
    }
    for(int i=1;i<n;i++){
       for(int wt=0;wt<=w;wt++){
          int notake=dp[i-1][wt];
          int take=INT_MIN;
          if(weight[i]<=wt){
              take=profit[i]+dp[i][wt-weight[i]];
          }
      dp[i][wt]=max(take,notake);

       }
    }
    return dp[n-1][w];
}


#include<bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // space optimization. tcO(w*n) and space compexity O(2w)
  vector<int>prev(w+1,0),curr(w+1,0);
    for(int wt=0;wt<=w;wt++){
       prev[wt]=(int)(wt/weight[0])*profit[0];
    }
    for(int i=1;i<n;i++){
       for(int wt=0;wt<=w;wt++){
          int notake=prev[wt];
          int take=INT_MIN;
          if(weight[i]<=wt){
              take=profit[i]+curr[wt-weight[i]];
          }
      curr[wt]=max(take,notake);

       }
       prev=curr;
    }
    return prev[w];
}
