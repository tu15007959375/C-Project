#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums;
	int res = 0;
	int pre = 0;
	for(int i =0;i<n;i++)
	{
		int tmp1;
		cin>>tmp1;
		nums.emplace_back(tmp1);
	}
	for(int i = 0;i<nums.size();i++)
	{
		if(nums[i]>pre)
		{
			res += (nums[i]-pre)*6+5;
		}
		else if(nums[i]<pre)
		{
			res += (pre-nums[i])*4+5;
		}
		pre = nums[i];
	}
	cout<<res;
	return 0;
}

