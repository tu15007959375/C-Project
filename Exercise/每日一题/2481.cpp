#include "util.h"

int numberOfCuts(int n) {
	if(n==1)
		return 0;
	if(n%2)
		return n;
	else
		return n/2;
}
int main()
{
	cout<<numberOfCuts(5);
	return 0;
}
