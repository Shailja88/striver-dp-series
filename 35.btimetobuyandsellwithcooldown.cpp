//memoization
#include<bits/stdc++.h>
using namespace std;
int fun(int i, int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
    if(i>=n)return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy){
        return dp[i][buy]=  max(-prices[i]+fun(i+1,0,prices,n,dp),fun(i+1,1,prices,n,dp));
    }
   else
   return dp[i][buy]= max(prices[i]+fun(i+2,1,prices,n,dp),fun(i+1,0,prices,n,dp));
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
      return fun(0,1,prices,prices.size(),dp);
}

#include<bits/stdc++.h>
using namespace std;


int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
    for (int buy = 0; buy <= 1; buy++) {

      if (buy)
        dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

      else
         dp[i][buy] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
    }
        }



      return dp[0][1];
}
#include<bits/stdc++.h>
using namespace std;


int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<int>one(2,0),two(2,0),three(2,0);
        for(int i=n-1;i>=0;i--){
     three[1] = max(-prices[i] + one[0], one[1]);
     three[0] = max(prices[i] + two[1], one[0]);
     two=one;
       one=three;
        }
 return three[1];
}

