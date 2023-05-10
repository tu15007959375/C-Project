#include"util.h"

int add(int a, int b) {
	if (b == 0) {
		return a;
	}
	
	// 转换成非进位和 + 进位
	return add(a ^ b, (a & b) << 1);
}

int main() {
	cout<<add(-1,2);
	return 0;
}

