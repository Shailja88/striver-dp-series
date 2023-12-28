#include<bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	
	int sum=0;
	for(auto in:arr){
		sum+=in;
	}
;
       vector<bool>prev(sum+1,0),curr(sum+1,0);
       prev[0]=curr[0]=true;
		   	   
    prev[arr[0]]=true;
     for(int i=1;i<n;i++){
		 for(int j=0;j<=sum/2;j++){
             bool notake=prev[j];
			 bool take=false;
			 if(arr[i]<=j)take=prev[j-arr[i]];
            curr[j]=notake|take;
		 }
		 prev=curr;
	 }

int ans=INT_MAX;
for(int i=0;i<=sum/2;i++){
	if(prev[i]==true){
          ans=min(ans,abs(sum-i-i));
	}
}
return ans;
}
