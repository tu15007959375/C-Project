#include"util.h"

int maxSubArray(vector<int>& nums) {
	if(nums.size()==0)
		return 0;
	if(nums.size()==1)
		return nums[0];
	vector<int> dp(nums.size(),0);
	dp[0]=nums[0];
	for(int i=1;i<nums.size();i++)
	{
		dp[i] = dp[i-1]>0?dp[i-1]+nums[i]:nums[i];
	}
	
	return *max_element(dp.begin(),dp.end());
}
int main() {
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout<<maxSubArray(nums);
	return 0;
}

