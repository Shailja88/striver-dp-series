#include<bits/stdc++.h>
using namespace std;
 

 int lps(string &str1,int i1,string &str2,int i2){
	 if(i1<0 || i2<0 )return 0;
     if(str1[i1]==str2[i2])
	 return 1+lps(str1,i1-1,str2,i2-1);
	
	 return max(lps(str1,i1-1,str2,i2),lps(str1,i1,str2,i2-1)); 
 
 }
int minimumInsertions(string &str)
{
  int s=str.size();
  string s1=str;
  reverse(str.begin(),str.end());
  return s-lps(str,s-1,s1,s-1);
}

#include<bits/stdc++.h>
using namespace std;
 
int minimumInsertions(string &str1)
{
  int s=str1.size();
  string str2=str1;
  reverse(str1.begin(),str1.end());
  vector<vector<int>>dp(s+1,vector<int>(s+1,0));
  for(int i=1;i<=s;i++){
    for(int j=1;j<=s;j++){
      if(str1[i-1]==str2[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }


  return s-dp[s][s];
}

