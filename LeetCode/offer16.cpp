#include"util.h"


double myPow(double x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n == -1) return 1 / x;
	double half = myPow(x, n >> 1);
	double mod = myPow(x, n & 1);
	return half * half * mod;
}
int main()
{
	cout<<myPow(2.1000,3);
	return 0; 
}

