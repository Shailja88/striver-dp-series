#include<bits/stdc++.h>
using namespace std;
//true for  buying  false for  selling TC=O(n) SC=O(n)
long fun(long *arr,int i,int n,int buy){
  if(i==n)return 0;
  //buy
   if(buy)
 return max(fun(arr,i+1,n,1),-arr[i]+fun(arr,i+1,n,0));
   else
  return max(fun(arr,i+1,n,0),arr[i]+fun(arr,i+1,n,1));
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
      
    return fun(values,0,n,1);
}
//memoization   TC=O(n) TC=O(n)+O(n)
#include<bits/stdc++.h>
using namespace std;
//true for  buying  false for  selling 
long fun(long *arr,int i,int n,int buy,vector<vector<long>>&dp){
  if(i==n)return 0;
  //buy
  if(dp[i][buy]!=-1)return dp[i][buy];
   if(buy)
 return dp[i][buy]= max(fun(arr,i+1,n,1,dp),-arr[i]+fun(arr,i+1,n,0,dp));
   else
  return  dp[i][buy]=max(fun(arr,i+1,n,0,dp),arr[i]+fun(arr,i+1,n,1,dp));
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
      vector<vector<long>>dp(n,vector<long>(2,-1));
    return fun(values,0,n,1,dp);
}


#include<bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *arr, int n)
{
    //Write your code here
      vector<vector<long>>dp(n+1,vector<long>(2,0));
      dp[n][0]=dp[n][1]=0;
      for(int i=n-1;i>=0;i--){
        
      for(int buy=0;buy<=1;buy++){
           if(buy)
         dp[i][buy]= max(dp[i+1][1],-arr[i]+dp[i+1][0]);
            else
           dp[i][buy]=max(dp[i+1][0],arr[i]+dp[i+1][1]);
}
      }
      return dp[0][1];
}


#include<bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *arr, int n)
{
    //Write your code here
      vector<long>ahead(2,0),curr(2,0);
      ahead[0]=ahead[1]=0;
      for(int i=n-1;i>=0;i--){
        
      for(int buy=0;buy<=1;buy++){
           if(buy)
         curr[buy]= max(ahead[1],-arr[i]+ahead[0]);
            else
           curr[buy]=max(ahead[0],arr[i]+ahead[1]);
}
  ahead=curr;
      }
      return ahead[1];
}

#include<bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *arr, int n)
{
      long currbuy,currnotbuy,aheadbuy,aheadnotbuy;
       aheadnotbuy=aheadbuy=0;
       for(int i=n-1;i>=0;i--)
      {currbuy= max(aheadbuy,-arr[i]+aheadnotbuy);
      currnotbuy=max(aheadnotbuy,arr[i]+aheadbuy);
      aheadbuy=currbuy;
       aheadnotbuy=currnotbuy;}
      
      return aheadbuy;
}
