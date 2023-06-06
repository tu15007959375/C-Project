#include "util.h"

int equalPairs(vector<vector<int>>& grid) {
	map<vector<int>,vector<int>> rowmap;
	map<vector<int>,vector<int>> colmap;
	int rescount = 0;
	for(int i = 0;i<grid.size();i++)
	{
		rowmap[grid[i]].push_back(i);
		vector<int> onecoltmp;
		for(int j = 0;j<grid[0].size();j++)
		{
			onecoltmp.push_back(grid[j][i]);
		}
		colmap[onecoltmp].push_back(i);
	}
	for(auto it:rowmap)
	{
		if(colmap.count(it.first))
			rescount += it.second.size()*colmap[it.first].size();
	}
	return rescount;
}
int main()
{
	vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
	cout<<equalPairs(grid);
	return 0;
}
