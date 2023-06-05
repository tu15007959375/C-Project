#include "util.h"


int mctFromLeafValues(vector<int>& arr) {
	int res = 0;
	stack<int> stk;
	for (int x : arr) {
		while (!stk.empty() && stk.top() <= x) {
			int y = stk.top();
			stk.pop();
			if (stk.empty() || stk.top() > x) {
				res += y * x;
			} else {
				res += stk.top() * y;
			}
		}
		stk.push(x);
	}
	while (stk.size() >= 2) {
		int x = stk.top();
		stk.pop();
		res += stk.top() * x;
	}
	return res;
}

int main()
{
	vector<int> arr ={3,7,2,12,15,10,3,9};
	cout<<mctFromLeafValues(arr);
	return 0;
}
