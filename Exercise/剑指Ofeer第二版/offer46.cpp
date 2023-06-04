#include"util.h"

//可以更改的地方
//num处改成str再用at
int translateNum(int num) {
	if(num == 0)
		return 1;
	vector<int> nums;
	while(num){
		nums.insert(nums.begin(),num%10);
		num /= 10;
	}
	nums.insert(nums.begin(),0);
	vector<int> dp(nums.size(),0);
	dp[1]=1;
	for(int i=2;i<nums.size();i++)
	{
		dp[i] += dp[i-1];
		if( nums[i-1]!=0 && (nums[i-1]*10+nums[i])<26)
		{
			if(i>2)
			{
				
				dp[i] += dp[i-2];
			}
			else
				dp[i]++;
		}
			
	}
	return dp[nums.size()-1];
}	

int main() {
	cout<<translateNum(26);
	return 0;
}

