#include "util.h"

int halveArray(vector<int>& nums) {
	multiset<double,greater<double>> numset;
	int sum=0;
	int res = 0;
	double needdel = 0;
	for(int x: nums)
	{
		numset.insert(x);
		sum += x;
	}
	double half = (double)sum/2;
	while(needdel<half){
		res++;
		double tmp = (double)(*numset.begin())/2;
		needdel += tmp;
		numset.erase(numset.begin());
		numset.insert(tmp);
	}
	return res;
}		
int main()
{
	vector<int> nums = {10000000,10000000,10000000,10000000,10000000,10000000};
	cout<<halveArray(nums);
	return 0;
}
