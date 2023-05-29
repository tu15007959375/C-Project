#include "util.h"

int averageValue(vector<int>& nums) {
	int res = 0;
	int tmp1,tmp2;
	int count = 0;
	for(int x:nums)
	{
		tmp1 = x%2;
		tmp2 = x%3;
		if(tmp1 == 0 && tmp2 == 0)
		{
			count++;
			res += x;
		}
	}
	if(count==0)
		return 0;
	return res/count;
}
int main()
{
	vector<int> nums = {1,3,6,10,12,15};
	cout<<averageValue(nums);
}
