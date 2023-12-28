
bool fun(vector<int>&arr, int k){
int n=arr.size();
vector<bool>prev(k+1,false),curr(k+1,false);
prev[0]=curr[0]=true;
if(arr[0]<=k)prev[arr[0]]=true;
for(int i=1;i<n;i++){
  for (int target = 1; target <= k; target++) {
    // take
    bool take = false;
    if (arr[i] <= target)
      take = prev[target - arr[i]];
    bool nottake = prev[target];
        // not take
        curr[target] = take|nottake;
        }
		prev=curr;
}
return prev[k];
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum=0;
	for(auto in:arr){
		sum+=in;
	}
	if(sum%2!=0)return false;

	return fun(arr,sum/2);
}
