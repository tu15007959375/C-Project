#include"util.h"

bool cmp(int a,int b){
	string x = to_string(a)+to_string(b);
	string y = to_string(b)+to_string(a);
	return x<y;
}
string minNumber(vector<int>& nums) {
	sort(nums.begin(),nums.end(),cmp);
	string res="";
	for(int x:nums)
		res += to_string(x);
	return res;
}		

int main() {
	vector<int> nums = {3,30,34,5,9};
	cout<<minNumber(nums);

	return 0;
}

