
#include<bits/stdc++.h>

using namespace std;
int mod=1000000007;
int fun(int i, int j,int isTrue,string &exp,  vector<vector<vector<int>>>&dp) {
    // Write your code here.
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    if(i>j)return 0;
    if(i==j){
        if(isTrue)return exp[i]=='T';
        else 
        return exp[i]=='F';
    }
    long long ways=0;
    for(int ind=i+1;ind<=j-1;ind+=2){
          long long lt=fun(i,ind-1,1,exp,dp);
          long long lf=fun(i,ind-1,0,exp,dp);
          long long rt=fun(ind+1,j,1,exp,dp);
          long long rf=fun(ind+1,j,0,exp,dp);
        if(exp[ind]=='&'){
             if(isTrue){
                 ways+=(lt%mod*rt%mod)%mod;
             }
             else{
                 ways+=((lf%mod*rf%mod)%mod+(lt%mod*rf%mod)%mod+(lf%mod*rt%mod)%mod)%mod;
             }

        }
        else if(exp[ind]=='|'){
              if(isTrue){
             ways+=((lt%mod*rt%mod)%mod+(lt%mod*rf%mod)%mod+(lf%mod*rt%mod)%mod)%mod;

              }
            else{
               ways+=(lf%mod*rf%mod)%mod;
            }

        }
        else{
            //xor
            if(isTrue)
            ways+=((lt%mod*rf%mod)%mod+(lf%mod*rt%mod)%mod)%mod;
             else
            ways+=(( lf%mod*rf%mod)%mod+(lt%mod*rt%mod)%mod)%mod;
        }

    }
    return dp[i][j][isTrue] =ways%mod;
}

int evaluateExp(string & exp) {
        int n=exp.size();
        //3ddp
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return fun(0,n-1,1,exp,dp);   
}
