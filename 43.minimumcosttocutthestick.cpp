#include <bits/stdc++.h>

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    int size=cuts.size();
    int mini=INT_MAX;
    vector<vector<int>>dp(size+1,vector<int>(size+1,-1));
    for(int i=n-1;i>=1;i--){
        
        for(int j=i;j<size;j++){
         for(int ind=i;ind<=j;ind++){
           int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
              mini=min(mini,cost);
         }
         dp[i][j]= mini;


        }
    }
    return dp[1][c];
}

#include <bits/stdc++.h>

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    int size=cuts.size();
    int mini=INT_MAX;
    vector<vector<int>>dp(size,vector<int>(size,0));
    for(int i=c;i>=1;i--){
        
        for(int j=1;j<=c;j++){
            mini=INT_MAX;
            if(i>j)continue;
         for(int ind=i;ind<=j;ind++){
             int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
              mini=min(mini,cost);
         }
         dp[i][j]= mini;


        }
    }
    return dp[1][c];
}
