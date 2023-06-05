#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	int b;
	cin>>a>>b;
	int sum = a+b;
	if(sum<1000&&sum>-1000)
	{
		cout<<sum;
		return 0;
	}
	string res;
	int count = 0;
	int flag = 1?sum<0:0;
	sum = abs(sum);
	while(sum!=0){
		count++;
		res = to_string(sum%10) +res;
		sum /= 10;
		if(count == 3)
		{
			res = ','+res;
			count = 0;
		}
	}
	if(res[0]==',')
		res.erase(0,1);
	if(flag)
		res = "-"+res;
	
	cout<<res;
	return 0;
}
