#include "util.h"

int pivotInteger(int n) {
	double res1 = sqrt((n*n+n)/2);
	int res = res1;
	return res == res1?res:-1;	
}
int main()
{
	cout<<pivotInteger(8);
	return 0;
}
