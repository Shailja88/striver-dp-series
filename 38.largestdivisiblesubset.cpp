///sort the array then apply intiution like lis 
#include<bits/stdc++.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr)
{
    int n=arr.size();
    int maxi=1;
    int lastindex=0;
    vector<int>dp(n,1),hash(n);
    vector<int>temp;
   sort(arr.begin(),arr.end());
   
    for(int i=1;i<n;i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
           if(arr[i]%arr[j]==0  && dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
            hash[i]=j;
            
         }
        }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
    }


    temp.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
         lastindex=hash[lastindex];
         temp.push_back(arr[lastindex]);

    }
    return temp;
}
