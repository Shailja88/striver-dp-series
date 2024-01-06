#include<bits/stdc++.h>
using namespace std;
 int fun(vector<int>&prices,int i,int buy,int n,int fee,vector<vector<int>>&dp)
 {   if(i>=n)return 0;
         if(dp[i][buy]!=-1)return dp[i][buy];
		  if(buy)
        return dp[i][buy]=max(-prices[i]+fun(prices,i+1,0,n,fee,dp),fun(prices,i+1,1,n,fee,dp));
          else return dp[i][buy]=max(prices[i]-fee+fun(prices,i+1,1,n,fee,dp),fun(prices,i+1,0,n,fee,dp));

 }
int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	  vector<vector<int>>dp(n,vector<int>(2,-1));
      return fun(prices,0,1,n,fee,dp);
}
#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	  vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
        dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
        dp[i][0]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
			
		}

    return dp[0][1];
}
#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	  vector<int>after(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--){
        curr[1]=max(-prices[i]+after[0],after[1]);
        curr[0]=max(prices[i]-fee+after[1],after[0]);
		after=curr;
			}

    return after[1];
}
