#include"util.h"

int numWays(int n) {
	if(n == 1||n == 0)
		return 1;
	
	vector<int> x(n+1);
	x[0] = 1;
	x[1]=1;
	for(int i=2;i<=n;i++){
		x[i] = (x[i-1]+x[i-2])%1000000007;
	}
	return x[n];
}
int main()
{
	cout<<numWays(7);
	return 0; 
}

