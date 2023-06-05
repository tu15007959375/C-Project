#include<iostream>
#include<vector>
#include<map>
#include <iomanip>
using namespace std;
int main()
{
	int a;
	int tmp1;
	double tmp2;
	cin>>a;
	map<int,double,greater<int>> hashmap;
	for(int i =0;i<a;i++)
	{	
		cin>>tmp1>>tmp2;
		hashmap[tmp1] = tmp2;
	}
	cin>>a;
	for(int i =0;i<a;i++)
	{	
		cin>>tmp1>>tmp2;
		hashmap[tmp1] += tmp2;
	}
	map<int,double>::iterator it = hashmap.begin();
	while(it!=hashmap.end())
	{
		if(it->second==0)
			it = hashmap.erase(it);
		else
			it++;
	}
	cout<<hashmap.size();
	for(auto it:hashmap)
		cout<<" "<<it.first<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<it.second;
	return 0;
}
