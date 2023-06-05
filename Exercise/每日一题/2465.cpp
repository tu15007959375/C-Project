#include "util.h"

int distinctAverages(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	set<double> resset;
	int i = 0,j = nums.size()-1;
	while(i<j)
	{
		resset.emplace((double)(nums[i]+nums[j])/2);
		i++;
		j--;
	}
	return resset.size();
}
int main()
{
	vector<int> nums = {4,1,4,0,3,5};
	cout<<distinctAverages(nums);
	return 0;
}
