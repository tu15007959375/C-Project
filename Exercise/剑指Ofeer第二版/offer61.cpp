#include"util.h"

bool isStraight(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int counts = count(nums.begin(),nums.end(),0);
	if(counts == 0)
	{
		for(int i=0;i<nums.size()-1;i++)
		{
			if(nums[i+1]-nums[i]!=1)
				return false;
		}
		return true;
	}
	else if (counts == 1)
	{
		int distance = 0;
		for(int i=1;i<nums.size()-1;i++)
		{
			int tmp = nums[i+1]-nums[i];
			if(tmp == 1)
				continue;
			else if(tmp == 2)
				distance++;
			else
				return false;
		}
		if(distance <= 1)
			return true;
		else
			return false;
	}
	else if(counts == 2)
	{
		int distance = 0;
		for(int i=2;i<nums.size()-1;i++)
		{
			int tmp = nums[i+1]-nums[i];
			if(tmp == 1)
				continue;
			else if(tmp == 2)
				distance++;
			else if(tmp == 3)
				distance += 2;
			else
				return false;
		}
		if(distance <= 2)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	vector<int> nums ={0,0,1,2,5};
	cout<<isStraight(nums);
	return 0;
}

