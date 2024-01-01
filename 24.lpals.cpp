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
		 prev[j]=1 +prev[j-1];
			// if notmatch
		else prev[j]= max(prev[j-1],prev[j]);
		 }
		
	 }
	//Write your code here
	return prev[t1];
	}
