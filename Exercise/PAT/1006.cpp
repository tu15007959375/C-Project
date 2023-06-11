#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	map<string,string> infomap1;
	map<string,string,greater<string>> infomap2;
	int m;
	string tmp1,tmp2,tmp3;
	cin>>m;
	for(int i =0;i<m;i++)
	{
		cin>>tmp1>>tmp2>>tmp3;
		infomap1[tmp2] = tmp1;
		infomap2[tmp3] = tmp1;
	}
	cout<<infomap1.begin()->second<<" "<<infomap2.begin()->second;
	return 0;
}

