#include"util.h"

long remain(int x,int a,int p)
{
	long rm=1;
	for(int i=0;i<a;i++){
		rm = (rm*x)%p;
	}
	return rm;
}
int cuttingRope(int n) {
	if(n <= 3)
		return n-1;
	int x = n/3;
	int y = n%3;
	if(y == 0)
		return remain(3,x,1000000007);
	else if(y == 1)
		return 4*remain(3,x-1,1000000007)%1000000007;
	else
		return 2*remain(3,x,1000000007)%1000000007;
}

int main()
{
	cout<<cuttingRope(200);
	return 0; 
}

