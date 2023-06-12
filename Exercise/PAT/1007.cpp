#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int m;
	cin>>m;
	vector<int> nums;
	int sum=-1,left = 0,right = m-1,tmp=0,tmp2;
	for(int i =0;i<m;i++)
	{
		int tmp1;
		cin>>tmp1;
		nums.emplace_back(tmp1);
	}
	for(int i =0; i<nums.size(); i++)
	{
		tmp += nums[i];
		if(tmp<0)
		{
			tmp = 0;
			tmp2 = i+1;
		}
		else if(tmp>sum)
		{
			sum = tmp;
			left = tmp2;
			right = i;
		}
	}
	if(sum<0)
		sum = 0;
	cout<<sum<<" "<<nums[left]<<" "<<nums[right];
	
	return 0;
}

