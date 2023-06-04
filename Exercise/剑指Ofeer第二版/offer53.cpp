#include"util.h"


int search(vector<int>& nums, int target) {
	unordered_map<int,int> cmap;
	for(int x:nums)
	{
		if(cmap.count(x)==0)
			cmap[x]=1;
		else
			cmap[x]++;
	}
	if(cmap.count(target))
		return cmap[target];
	else
		return 0;
}
int main() {
	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;
	cout<<search(nums,target);

	return 0;
}

