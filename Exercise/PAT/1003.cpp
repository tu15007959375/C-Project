#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;
map<int,vector<int>> resmap;
vector<vector<int>> cityinfo;
vector<bool> cityflag;
vector<int> cityteams;
int city;
void dfs(int start,int end,int roadcount, int teamscount)
{
	if(start == end)
	{
		resmap[roadcount].push_back(teamscount);
		return;
	}
	int i = 0 ;
	while(i<city)
	{
		if(cityinfo[start][i]>0&&i!=start&&!cityflag[i])
		{
			cityflag[i] = true;
			dfs(i,end,roadcount+cityinfo[start][i],teamscount+cityteams[i]);
			cityflag[i] = false;
		}
		i++;
	}
	
}
int main()
{
	int road,start,end;
	cin>>city>>road>>start>>end;
	for(int i =0;i<city;i++)
	{
		int tmp;
		cin>>tmp;
		cityteams.push_back(tmp);
	}
	cityinfo.resize(city,vector<int>(city,-1));
	cityflag.resize(city,false);
	for(int i = 0;i<road;i++)
	{
		int x,y,val;
		cin>>x>>y>>val;
		cityinfo[x][y] = val;
		cityinfo[y][x] = val;
	}
	cityflag[start] = true;
	dfs(start,end,0,cityteams[start]);
	auto it = resmap.begin();
	cout<<it->first<<" "<<*max_element(it->second.begin(),it->second.end());
		
	return 0;
}
