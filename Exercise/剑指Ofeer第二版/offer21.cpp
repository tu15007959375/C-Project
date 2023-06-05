#include"util.h"
//左奇右偶
vector<int> exchange(vector<int>& nums) {
	int left=0;
	int right=nums.size()-1;
	while(left<right){
		if(nums[left]%2==0 && nums[right]%2)
		{
			swap(nums[left],nums[right]);
		}
		if(nums[left]%2)
			left++;
		if(nums[right]%2==0)
			right--;
	}
	return nums;
}

int main()
{
	vector<int> nums = {1,2,3,4};
	nums = 	exchange(nums);
	for(int i=0;i<nums.size();i++)
		cout<<nums[i];
	return 0;
}

