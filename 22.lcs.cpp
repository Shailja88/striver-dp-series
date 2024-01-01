//memoization TC =O(s1*t2)   SC=O(s1*t1) + O(s1+t1)
#include<bits/stdc++.h>
using namespace std;
int fun(string &s, int ind1, string &t, int ind2,vector<vector<int>>&dp) {
  if (ind1 < 0 || ind2 < 0)
    return 0;
     // if match
  if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
  if (s[ind1] == t[ind2])
    return dp[ind1][ind2]=1 + fun(s, ind1 - 1, t, ind2 - 1,dp);
     // if notmatch
  return dp[ind1][ind2]= max(fun(s, ind1, t, ind2 - 1,dp), fun(s, ind1 - 1, t, ind2 ,dp));
}
int lcs(string s, string t)
{ 
  int s1=s.size();
	int t1=t.size();
	vector<vector<int>>dp(s1,vector<int>(t1,-1));
	return fun(s,s1-1,t,t1-1,dp);
}



///tabulationn
#include<bits/stdc++.h>
using namespace std;
//TC=(s1*t1) SC=O(s1*t1);
int lcs(string s, string t)
{ 
	int s1=s.size();
	int t1=t.size();
	vector<vector<int>>dp(s1+1,vector<int>(t1+1,0));
	 for(int i=1;i<=s1;i++){
		 for(int j=1;j<=t1;j++){
           // if match
		
		if (s[i-1] == t[j-1])
		 dp[i][j]=1 +dp[i - 1][j-1];
			// if notmatch
		else dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
		 }
	 }
	//Write your code here
	return dp[s1][t1];
	}


#include<bits/stdc++.h>
using namespace std;
//TC=(s1*t1) SC=O(t1);
int lcs(string s, string t)
{ 
	int s1=s.size();
	int t1=t.size();
	vector<int>prev(t1+1,0),curr(t1+1,0);
	 for(int i=1;i<=s1;i++){
		 for(int j=1;j<=t1;j++){
           // if match
		
		if (s[i-1] == t[j-1])
		 curr[j]=1 +prev[j-1];
			// if notmatch
		else curr[j]= max(curr[j-1],prev[j]);
		 }
		 prev=curr;
	 }
	//Write your code here
	return prev[t1];
	}


