#include"util.h"
////超时
//int reversePairs2(vector<int>& nums) {
//	if(nums.size()==0||nums.size()==1)
//		return 0;
//	vector<int> dp(nums.size()+1,0);
//	dp[1]=0;
//	for(int i=2;i<=nums.size();i++)
//	{
//		dp[i] += dp[i-1];
//		int count = 0;
//		for(int j=0;j<i-1;j++)
//		{
//			if(nums[j]>nums[i-1])
//				count++;
//		}
//		dp[i] += count;
//	}
//	return dp[nums.size()];
//}
////超时2
//int reversePairs2(vector<int>& nums) {
//	if(nums.size()==0||nums.size()==1)
//		return 0;
//	vector<int> dp(nums.size()+1,0);
//	dp[1]=0;
//	multiset<int> numset;
//	numset.insert(nums[0]);
//	for(int i=2;i<=nums.size();i++)
//	{
//		dp[i] += dp[i-1];
//		int pos = numset.size()-distance(numset.begin(),numset.upper_bound(nums[i-1]));
//		dp[i] += pos;
//		numset.insert(nums[i-1]);
//	}
//	return dp[nums.size()];
//}
int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
	// 终止条件
	if (l >= r) return 0;
	// 递归划分
	int m = (l + r) / 2;
	int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
	// 合并阶段
	int i = l, j = m + 1;
	for (int k = l; k <= r; k++)
		tmp[k] = nums[k];
	for (int k = l; k <= r; k++) {
		if (i == m + 1)
			nums[k] = tmp[j++];
		else if (j == r + 1 || tmp[i] <= tmp[j])
			nums[k] = tmp[i++];
		else {
			nums[k] = tmp[j++];
			res += m - i + 1; // 统计逆序对
		}
	}
	return res;
}
int reversePairs(vector<int>& nums) {
	vector<int> tmp(nums.size());
	return mergeSort(0, nums.size() - 1, nums, tmp);
}
int main() {
	vector<int> nums = {7,5,6,4};
	cout<<reversePairs(nums);

	return 0;
}

