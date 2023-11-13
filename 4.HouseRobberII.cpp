//TC=O(N) SC=O(N);
#include <bits/stdc++.h> 
long long int solve(vector<int>&nums){
    //using tabulation and space optimization
     long long int prev1=nums[0],prev2=0,pick=0,notpick=0;
      for(int i=1;i<nums.size();i++){
          pick=nums[i]+prev2;
          notpick=prev1;
          prev2=prev1;
          prev1=max(notpick,pick);

      }
      return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int>temp1,temp2;
    int n=valueInHouse.size();
    if(n==0)return 0;
    if(n==1)return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(valueInHouse[i]);
        if(i!=n-1)temp2.push_back(valueInHouse[i]);

    }
    return max(solve(temp1),solve(temp2));
}
