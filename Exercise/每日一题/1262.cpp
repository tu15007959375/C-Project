#include "util.h"



int maxSumDivThree(vector<int>& nums) {
	int N = nums.size();
	int remainder[3] = {0};
	for(int i = 0; i < N; i++){
		int a,b,c;
		a = remainder[0] + nums[i];
		b = remainder[1] + nums[i];
		c = remainder[2] + nums[i];
		remainder[a%3] = max(remainder[a%3], a);
		remainder[b%3] = max(remainder[b%3], b);
		remainder[c%3] = max(remainder[c%3], c);
	}
	return remainder[0];
}
int main()
{
	vector<int> nums = {3,6,5,1,8};
	cout<<maxSumDivThree(nums);
	return 0;
}
