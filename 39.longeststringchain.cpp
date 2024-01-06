#include<bits/stdc++.h>
using namespace std;
bool compare(string &s1,string &s2){
    if(s1.size()-1!=s2.size())return false;
    int first=0,second=0;
    while( first<s1.size()){
        if(s1[first]==s2[second]){
            first++;second++;
        }
        else{
            first++;
        }
    }
    if(first==s1.size() && second==s2.size())
    return true;
    return false;
}
bool cmp(string &s1,string &s2){
    return s1.size()<s2.size();
}
int longestStrChain(vector<string> &arr){
    sort(arr.begin(),arr.end(),cmp);
    int n=arr.size();
    vector<int>dp(n,1);
    int maxi=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
         if(compare(arr[i],arr[j])==true&&dp[i]<dp[j]+1){
             dp[i]=dp[j]+1;
             }
         maxi=max(maxi,dp[i]);
        }
    }
    return maxi;
}




