#include <bits/stdc++.h> 

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
int longestPalindromeSubsequence(string str)
{
   	string str1=str;
	reverse(str.begin(),str.end());
 return lcs(str,str1);
}
