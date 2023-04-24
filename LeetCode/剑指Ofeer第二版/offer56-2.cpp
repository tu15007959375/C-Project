#include"util.h"

int singleNumber(vector<int>& nums) {
	map<int,int> cmap;
	for(int x:nums)
	{
		if(cmap.count(x)==0)
			cmap[x]=1;
		else
			cmap[x]=-1;
	}
	for(auto it:cmap)
	{
		if(it.second == 1)
			return it.first;
	}
	return NULL;	
}

int main() {
	vector<int> nums ={3,4,3,3};
	cout<<singleNumber(nums);
	return 0;
}

