#include"util.h"

int cuttingRope(int n) {
	if(n <= 3)
		return n-1;
	int x = n/3;
	int y = n%3;
	int sum=1;
	if(y == 0)
		return pow(3,x);
	else if(y == 1)
		return 4*pow(3,x-1);
	else
		return 2*pow(3,x);
	return sum;
}

int main()
{
	cout<<cuttingRope(4);
	return 0; 
}

