#include<iostream>
#include<vector>
#include<map>
#include <iomanip>
using namespace std;
int main()
{
	int a;
	int b;
	int tmp1;
	double tmp2;
	cin>>a;
	if(a==0)
	{
		cout<<0;
		return 0;
	}
	vector<pair<int,double>> ph1;
	vector<pair<int,double>> ph2;
	map<int,double,greater<int>> resmap;
	for(int i =0;i<a;i++)
	{
		cin>>tmp1;
		cin>>tmp2;
		ph1.emplace_back(tmp1,tmp2);
	}
	cin>>b;
	if(b==0)
	{
		cout<<0;
		return 0;
	}
	for(int i =0;i<b;i++)
	{
		cin>>tmp1;
		cin>>tmp2;
		ph2.emplace_back(tmp1,tmp2);
	}
	for(int i = 0;i<a; i++)
	{
		
		for(int j = 0; j<b; j++)
		{
			int x = ph1[i].first+ph2[j].first;
			double y = ph1[i].second*ph2[j].second;
			resmap[x] += y;
			if(resmap[x]==0)
				resmap.erase(x);
		}
	}


	cout<<resmap.size();
	for(auto it:resmap)
		cout<<" "<<it.first<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<it.second;
		
	return 0;
}
