#include"util.h"
//自己的方法
vector<int> singleNumbers(vector<int>& nums) {
	vector<int> res;
	if(nums.size()==0)
		return res;
	if(nums.size()==1)
		return vector<int>(1,nums[0]);
	sort(nums.begin(),nums.end());
	int pre=nums[0],now=nums[0];
	int i=1;
	while(i<nums.size()){
		now = nums[i];
		if(now!=pre)
		{
			res.push_back(pre);
			pre = now;
		}
		else
		{
			i++;
			if(i<nums.size())
				pre = nums[i];
		}
		i++;
	}
	if(nums[nums.size()-1]!=nums[nums.size()-2])
		res.push_back(nums[nums.size()-1]);
	return res;
}
vector<int> singleNumbers2(vector<int>& nums) {
	int x = 0, y = 0, n = 0, m = 1;
	for(int num : nums)         // 1. 遍历异或
		n ^= num;
	while((n & m) == 0)         // 2. 循环左移，计算 m
		m <<= 1;
	for(int num : nums) {       // 3. 遍历 nums 分组
		if(num & m) x ^= num;   // 4. 当 num & m != 0
		else y ^= num;          // 4. 当 num & m == 0
	}
	return vector<int> {x, y};  // 5. 返回出现一次的数字
}
int main() {
	vector<int> nums = {3,2,1,3};
	vector<int> res = singleNumbers(nums);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}

