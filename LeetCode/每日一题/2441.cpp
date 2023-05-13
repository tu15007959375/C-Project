#include "util.h"

int findMaxK(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int left = 0;
	int right = nums.size()-1;
	while(left!=right){
		int tmp = nums[left]+nums[right];
		if(tmp == 0)
			return abs(nums[left]);
		else if(tmp > 0)
			right--;
		else
			left++;
	}
	return -1;
}
int main()
{
	vector<int> nums = {-10,8,6,7,-2,-3};
	cout<<findMaxK(nums);
}
