#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k)
{
  vector<vector<int>>after(2,vector<int>(k+1,0));
    vector<vector<int>>curr(2,vector<int>(k+1,0));
 for(int i=n-1;i>=0;i--){
      for(int buy=0;buy<=1;buy++){
          for(int cap=1;cap<=k;cap++){
            if(buy){

          curr[buy][cap]=max(-prices[i]+after[0][cap],after[1][cap]);

            }
            else{
                curr[buy][cap]=max(prices[i]+after[1][cap-1],after[0][cap]);
       }
       }
      }
      after=curr;
  }
  return after[1][k];
}

///with the help of transation number if transaction no is even then buy else sell 
#include <bits/stdc++.h> 
int fun(vector<int>&prices,int i,int transno,int k,int n){
    if(i==n || transno>=2*k)return 0;
     ///if even then buy
          if(transno%2==0){
             return max(-prices[i]+fun(prices,i+1,transno+1,k,n),fun(prices,i+1,transno,k,n));
                  }
                   //if odd then sell
     else{
        return max(prices[i]+fun(prices,i+1,transno+1,k,n),fun(prices,i+1,transno,k,n));
    }

}
int maximumProfit(vector<int> &prices, int n, int k)
{
  return fun(prices,0,0,k,n);
}

////memoization
#include <bits/stdc++.h> 
int fun(vector<int>&prices,int i,int transno,int k,int n, vector<vector<int>>&dp){
    if(i==n || transno>=2*k)return 0;
    if(dp[i][transno]!=-1)return dp[i][transno];
     ///if even then buy

          if(transno%2==0){
             return dp[i][transno]= max(-prices[i]+fun(prices,i+1,transno+1,k,n,dp),fun(prices,i+1,transno,k,n,dp));
                  }
                   //if odd then sell
     else{
        return dp[i][transno]=max(prices[i]+fun(prices,i+1,transno+1,k,n,dp),fun(prices,i+1,transno,k,n,dp));
    }

}
int maximumProfit(vector<int> &prices, int n, int k)
{      vector<vector<int>>dp(n,vector<int>(k*2,-1));
  return fun(prices,0,0,k,n,dp);
}
///tabulation
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k)
{      vector<vector<int>>dp(n+1,vector<int>(k*2+1,0));
       for(int i=n-1;i>=0;i--){
         for(int transno=2*k-1;transno>=0;transno--){
        if(transno%2==0)
            dp[i][transno]= max(-prices[i]+dp[i+1][transno+1],dp[i+1][transno]);
             
        else
            dp[i][transno]=max(prices[i]+dp[i+1][transno+1],dp[i+1][transno]);
    

         }
       }
      return dp[0][0];
}



///space optimization

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k)
{      vector<int>after(k*2+1,0);
       vector<int>curr(k*2+1,0);
       for(int i=n-1;i>=0;i--){
         for(int transno=2*k-1;transno>=0;transno--){
        if(transno%2==0)
            curr[transno]= max(-prices[i]+after[transno+1],after[transno]);
             
        else
            curr[transno]=max(prices[i]+after[transno+1],after[transno]);
    

         }

          after=curr;
       }
      return after[0];
}



