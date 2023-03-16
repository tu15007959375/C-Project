#include"util.h"

int cuttingRope(int n) {
	if(n <= 3)
		return n-1;
	int x = n/3;
	int y = n%3;
	int sum=1;
	for(int i=0;i<(x-y);i++){
		sum *= x;
	}
	for(int i=0;i<y;i++){
		sum *= (x+1);
	}
	return sum;
}

int main()
{
	cout<<cuttingRope(4);
	return 0; 
}

