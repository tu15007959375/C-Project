#include"util.h"

vector<int> twoSum(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		if (nums[left] + nums[right] < target)  // 和太小了，nums[left] 可以再大点
			left++;
		else if (nums[left] + nums[right] > target) // 和太大了，nums[right] 可以再小一点
			right--;
		else 
			return vector<int> {nums[left], nums[right]};
	}
	return vector<int> {-1, -1};
}
int main() {
	vector<int> nums = {2,7,11,15};
	vector<int> res = twoSum(nums,9);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}

