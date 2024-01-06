//memoization

#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>&prices,int i,int cap,int buy,   vector<vector<vector<int>>>&dp){
   if(cap==0)return 0;
   if(i==prices.size())return 0;
   if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
   if(buy)
   return dp[i][buy][cap]=max(-prices[i]+fun(prices,i+1,cap,0,dp),fun(prices,i+1,cap,1,dp));
  else
  return dp[i][buy][cap]=max(prices[i]+fun(prices,i+1,cap-1,1,dp),fun(prices,i+1,cap,0,dp));
}
int maxProfit(vector<int>& prices)

{   
    int n=prices.size();
     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return fun(prices,0,2,1,dp);
}
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)

{   
    int n=prices.size();
     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
      for(int i=n-1;i>=0;i--){
          for(int buy=0;buy<=1;buy++){
              for(int cap=1;cap<=2;cap++){
               
            if(buy)
           dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
            else
           dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);


              }
          }
      }

return dp[0][1][2];
}

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)

{   
    int n=prices.size();
     vector<vector<int>>after(2,vector<int>(3,0));
     vector<vector<int>>curr(2,vector<int>(3,0));

      for(int i=n-1;i>=0;i--){
          for(int buy=0;buy<=1;buy++){
              for(int cap=1;cap<=2;cap++){
               
            if(buy)
         curr[buy][cap]=max(-prices[i]+after[0][cap],after[1][cap]);
            else
          curr[buy][cap]=max(prices[i]+after[1][cap-1],after[0][cap]);


              }
          }
          after=curr;
      }

return after[1][2];
}
