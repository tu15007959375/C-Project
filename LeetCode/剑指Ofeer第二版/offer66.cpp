#include"util.h"

vector<int> constructArr(vector<int>& a) {
	int len = a.size();
	if(len == 0) return {};
	vector<int> b(len, 1);
	b[0] = 1;
	int tmp = 1;
	for(int i = 1; i < len; i++) {
		b[i] = b[i - 1] * a[i - 1];
	}
	for(int i = len - 2; i >= 0; i--) {
		tmp *= a[i + 1];
		b[i] *= tmp;
	}
	return b;
}

int main() {
	vector<int> a = {1,2,3,4,5};
	vector<int> res = constructArr(a);
	for(int x: res)
		cout<<x<<"\t";
	return 0;
}

