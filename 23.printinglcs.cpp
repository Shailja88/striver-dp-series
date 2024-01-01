
#include <bits/stdc++.h>
using namespace std;
string lcs(string s,string t){
    //use tabulation
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int size=dp[n][m];
    for(int i=0;i<size;i++){
        ans+="%";
    }
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[size-1]=t[j-1];
            i=i-1;
            j=j-1;
            size=size-1;
        } 
        else if(dp[i-1][j]>dp[i][j-1]){
            i=i-1;
        }
        else{
            //dp[i-1]<dp[j-1]
            j=j-1;
        }
    }
    return ans;
}
int main()
{
    string s=  lcs("abcdefij","ijb");
    cout<<s;
    return 0;
}
