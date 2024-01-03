#include <bits/stdc++.h>
string shortestSupersequence(string a, string b) {
  // Write your code here.
  int n = a.size(), m = b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  /// create dp table
  for (int i = 1; i <= n; i++)
   {
	for(int j=1;j<=m;j++){
         if(a[i-1]==b[j-1])
			 dp[i][j]=1+dp[i-1][j-1];
	     else if(dp[i-1][j]>dp[i][j-1])
              dp[i][j]=dp[i-1][j];
     	 else
              dp[i][j]=dp[i][j-1];
      }
  }
     int i=n,j=m; string s="";
	 while(i>0 && j>0){
       if(a[i-1]==b[j-1]){
		   s+=a[i-1];
		   i--;j--;
	   }
         else if(dp[i-1][j]>dp[i][j-1])
             {
				 s+=a[i-1];
				 i--;
			 }
     	 else
             {
				 s+=b[j-1];j--;
			 }


	 }
    while(i>0) {s+=a[i-1] ;i--;}
	while(j>0)  {s+=b[j-1] ;j--;}
   reverse(s.begin(),s.end());
   return s;
}   
