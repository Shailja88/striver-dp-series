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

//tabulation
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int distinctSubsequences(string &s1, string &s2)
{
    int n=s1.size();
	int m=s2.size();
    
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++)dp[i][0]=1;
     for(int i1=1;i1<=n;i1++){
		 for(int i2=1;i2<=m;i2++){
                   if (s1[i1 - 1] == s2[i2 - 1]) {
                     dp[i1][i2] =
                         (dp[i1 - 1][i2 - 1] % mod + dp[i1 - 1][i2] % mod) %
                         mod;
                   } else
                     dp[i1][i2] = dp[i1 - 1][i2] % mod;
                 }
     }
return dp[n][m];
}
//space optimization
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int distinctSubsequences(string &s1, string &s2)
{
    int n=s1.size();
	int m=s2.size();
    
	vector<int>prev(m+1,0),curr(m+1,0);
      prev[0]=curr[0]=1;
     for(int i1=1;i1<=n;i1++){
		 for(int i2=1;i2<=m;i2++){
                   if (s1[i1 - 1] == s2[i2 - 1]) {
                    curr[i2] =
                         (prev[i2 - 1] % mod + prev[i2] % mod) %
                         mod;
                   } else
                     curr[i2] = prev[i2] % mod;
                 }
				 prev=curr;
     }
return prev[m];
}

