#include "util.h"

vector<int> applyOperations(vector<int>& nums) {
	vector<int> res;
	for(int i = 0; i <nums.size()-1; i++)
	{
		if(nums[i]==0)
			continue;
		else if(nums[i]==nums[i+1])
		{
			res.emplace(res.end(),2*nums[i]);
			nums[i+1] =0;
		}
		else
		{
			res.emplace(res.end(),nums[i]);
		}
			
	}
	if(nums[nums.size()-1]!=0)
		res.emplace(res.end(),nums[nums.size()-1]);
	for(int i = res.size();i<nums.size();i++)
		res.emplace(res.end(),0);
	return res;
}
int main()
{
	vector<int> nums = {0,1};
	vector<int> res = applyOperations(nums);
	for(int x: res)
		cout<<x<<"\t";
	return 0;
}
