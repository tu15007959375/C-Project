#include"util.h"


int missingNumber(vector<int>& nums) {
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]!=i)
			return i;
	}
	return nums.size();
}
int main() {
	vector<int> nums = {0,1,2,3,4,5,6,7,9};
	cout<<missingNumber(nums);

	return 0;
}

