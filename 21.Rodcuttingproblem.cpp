int fun(vector<int>& price, int k, int i,vector < vector < int>> dp) {

    if (i == 0 ) {
        return price[0]*k;
    }
  if(dp[i][i+1]!=-1)return dp[i][i+1];
    int notTake = fun(price, k, i - 1,dp);
    int take =INT_MIN;
	if((i+1)<=k) 
	take =price[i] + fun(price, k - (i + 1), i,dp);

    return  dp[i][i+1]= max(take, notTake);
}

int cutRod(vector<int> &price, int k){
 vector < vector < int>> dp(price.size(),vector<int>(k + 1, -1));
return fun(price, k, price.size() - 1, dp);
}
#include<bits/stdc++.h>
int cutRod(vector<int> &price, int k){
 vector < vector < int>> dp(price.size(),vector<int>(k + 1, 0));
 for(int i=0;i<=k;i++){
       dp[0][i]=i*price[0];
 }  
 for(int i=1;i<price.size();i++){
       for (int j = 0; j <= k; j++) {
         int notake = dp[i - 1][j];
         int take = INT_MIN;
         if ((i + 1) <= j)
           take = price[i]+dp[i][j - i - 1];
         dp[i][j] = max(take, notake);
       }

       
 }
 return dp[price.size() - 1][k];
}
