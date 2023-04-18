#include"util.h"

int movingCount(int m, int n, int k) {
	if(k==0)
		return 0;
	int res = 0;
	if(k<min(m,n))
	{
		for(int i=1;i<=k+1;i++)
			res += i;
	}
	else
	{
		
	}
	return res;
}

int main()
{
	cout<<movingCount(2,3,1);
	return 0; 
}

