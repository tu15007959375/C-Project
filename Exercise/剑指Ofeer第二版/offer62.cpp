#include"util.h"
//超时
int lastRemaining1(int n, int m) {
	vector<int> nums;
	for(int i = 0;i<n;i++)
		nums.push_back(i);
	int pos = m-1;
	int len = nums.size();
	if(m>n)
		pos = m%n-1;
	while(len != 1){
		vector<int>::iterator it = nums.begin() + pos;
		int tmp = len - pos - 1;
		nums.erase(it);
		len = nums.size();
		if(tmp < m)
		{
			int x = (m-tmp)%len;
			if( x == 0)
				pos = len-1;
			else
				pos  = x-1;		
		}
		else
			pos = pos + m -1;
	}
	return nums[0];
}
int lastRemaining(int n, int m) {
	int x = 0;
	for (int i = 2; i <= n; i++) {
		x = (x + m) % i;
	}
	return x;
}
int main() {
	cout<<lastRemaining(5,2);
	return 0;
}

