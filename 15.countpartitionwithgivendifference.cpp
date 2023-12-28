#include <bits/stdc++.h> 
int mod=1e9+7;
int fun(vector<int>&arr, int sum,int i,vector<vector<int>>&dp){
    if(i==0){
          if(sum==0 && arr[0]==0)return 2;
          if(sum==0||sum==arr[0])return 1;
          return 0;
  }
  if(dp[i][sum]!=-1)return dp[i][sum];
  //take
  int take=0;
  if(sum>=arr[i])take=fun(arr,sum-arr[i],i-1,dp);
  int nottake=fun(arr, sum, i-1,dp); //notake
   return dp[i][sum]= (take%mod+nottake%mod)%mod;
 
}
int countPartitions(int n, int d, vector<int> &arr) {
    /*
    ts=s1+s2;
    s1-s2=d
    ts-s2-s2=d
    ts-2s2=d
    (ts-d)/2=s2;
    */

int ts=0;
for(auto in:arr){
    ts+=in;
}
 
 if(ts-d<0 || (ts-d)%2)return 0;
 int s2=(ts-d)/2;
 vector<vector<int>>dp(n,vector<int>(s2+1,-1));
 return fun(arr,s2,n-1,dp);


}


////tabulation
#include <bits/stdc++.h>
int mod=1e9+7;
int fun(vector<int>&arr, int k,int n){
   vector<vector<int>>dp(n,vector<int>(k+1,0));
 if(arr[0]==0)dp[0][0]=2;     
 else dp[0][0]=1; 

if(arr[0]!=0 && arr[0]<=k)dp[0][arr[0]]=1;
for(int i=1;i<n;i++){
    for(int j=0;j<=k;j++){
        int notake=dp[i-1][j];
        int take=0;
        if(arr[i]<=j)take=dp[i-1][j-arr[i]];
        dp[i][j]=(take+notake)%(mod);
    }
}
return dp[n-1][k];


}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.tabulation
     int ts=0;
     for(auto in:arr){
         ts+=in;
     }
    /* s1-s2=d;
     s1+s2=ts;
     ts-s2-s2=d;
     (ts-d)/2=s2;
*/
    if(ts-d<0 || (ts-d)%2)return 0;
       return fun(arr,(ts-d)/2,n);
}


#include <bits/stdc++.h>
int mod=1e9+7;
int fun(vector<int>&arr, int k,int n){
   vector<int>prev(k+1,0),curr(k+1,0);
 if(arr[0]==0)prev[0]=curr[0]=2;     
 else prev[0]=curr[0]=1; 

if(arr[0]!=0 && arr[0]<=k)prev[arr[0]]=1;
for(int i=1;i<n;i++){
    for(int j=0;j<=k;j++){
        int notake=prev[j];
        int take=0;
        if(arr[i]<=j)take=prev[j-arr[i]];
       curr[j]=(take+notake)%(mod);
    }
    prev=curr;
}
return prev[k];


}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.tabulation
     int ts=0;
     for(auto in:arr){
         ts+=in;
     }
    /* s1-s2=d;
     s1+s2=ts;
     ts-s2-s2=d;
     (ts-d)/2=s2;
*/
    if(ts-d<0 || (ts-d)%2)return 0;
       return fun(arr,(ts-d)/2,n);
}


