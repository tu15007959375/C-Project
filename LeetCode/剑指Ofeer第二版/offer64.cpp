#include"util.h"

int sumNums(int n) {
	n && (n += sumNums(n-1));
	return n;
}
int main() {
	cout<<sumNums(4);
	return 0;
}

