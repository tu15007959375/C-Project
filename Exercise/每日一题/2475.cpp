#include "util.h"

int unequalTriplets(vector<int>& nums) {
	map<int,int> countmap;
	vector<int> mulvec;
	int res = 0;
	for(int x:nums)
		countmap[x]++;
	for(auto x:countmap)
		mulvec.emplace_back(x.second);
	if(mulvec.size()<3)
		return 0;
	for(int i = 0;i<mulvec.size()-2;i++)
	{
		for(int j = i+1;j<mulvec.size()-1;j++)
		{
			for(int k = j+1;k<mulvec.size();k++)
			{
				res += mulvec[i]*mulvec[j]*mulvec[k];
			}
		}
	}
	return res;
}
int main()
{
	vector<int> nums = {4,4,2,4,3};
	cout<<unequalTriplets(nums);
	return 0;
}
