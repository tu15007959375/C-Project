#include"util.h"
//超时方法
int fib1(int n) {
	if(n == 1)
		return 1;
	if(n == 0)
		return 0;
	return (fib1(n-1)+fib1(n-2))%1000000007;
}

int fib(int n) {
	if(n == 1)
		return 1;
	if(n == 0)
		return 0;
	vector<int> x(n+1);
	x[0] = 0;
	x[1]=1;
	for(int i=2;i<=n;i++){
		x[i] = (x[i-1]+x[i-2])%1000000007;
	}
	return x[n];
}
int main()
{

	cout<<fib(45);
	return 0; 
}

