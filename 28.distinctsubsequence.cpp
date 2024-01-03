#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int fun(string s1,int i1,string s2,int i2,vector<vector<int>>&dp){
	if(i2<0)return 1;
	if(i1<0)return 0;
	if(dp[i1][i2]!=-1)return dp[i1][i2];
    
 if(s1[i1]==s2[i2]){
		 return dp[i1][i2]= (fun(s1,i1-1,s2,i2-1,dp)%mod+fun(s1,i1-1,s2,i2,dp)%mod)%mod;
	 }
	 return dp[i1][i2]=fun(s1,i1-1,s2,i2,dp)%mod;
}
int distinctSubsequences(string &str, string &sub)
{
    int n=str.size();
	int m=sub.size();

	vector<vector<int>>dp(n,vector<int>(m,-1));
    return fun(str,n-1,sub,m-1,dp);

}
