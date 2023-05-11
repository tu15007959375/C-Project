#include "util.h"

vector<int> twoSum(vector<int>& nums, int target) {
	map<int,vector<int>> vmap;
	vector<int> res;
	for(int i = 0;i<nums.size();i++)
	{
		vmap[nums[i]].push_back(i);
	}
	for(auto it:vmap)
	{
		int last = target - it.first;
		if(last == it.first)
		{
			if(it.second.size()>=2)
			{
				res.push_back(it.second[0]);
				res.push_back(it.second[1]);
				return res;
			}
			else
				continue;
		}
		else
		{
			auto tmp = vmap.find(last);
			if(tmp!=vmap.end())
			{
				res.push_back(it.second[0]);
				res.push_back(tmp->second[0]);
				return res;
			}
		}
	}
	
	return res;
}

int main()
{
	vector<int> nums = {-3,4,3,90};
	vector<int> res = twoSum(nums,0);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}
