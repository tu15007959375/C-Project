#include"util.h"

int majorityElement(vector<int>& nums) {
	if(nums.size()==0)
		return -1;
	if(nums.size()==1)
		return nums[0];
	int half = nums.size()/2+1;
	map<int,int> countmap;
	for(int tmp:nums)
	{
		if(countmap.find(tmp)==countmap.end())
			countmap[tmp]=1;
		else
			countmap[tmp]++;
		if(countmap[tmp]>=half)
		{
			return tmp;
		}
		
	}
	return -1;
}
int main() {
	vector<int> nums = {1,2,3,2,2,2,5,4,2};
	int rs = majorityElement(nums);
	cout<<"rs:"<<rs;
	return 0;
}

