#include"util.h"


int hammingWeight(uint32_t n) {
	int res = 0;
	while(n){
		res++;
		n = n&(n-1);
	}
	return res;
}
int main()
{
	cout<<hammingWeight(11);
	return 0; 
}

