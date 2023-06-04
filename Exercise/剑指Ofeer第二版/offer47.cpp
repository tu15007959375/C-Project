#include"util.h"
//贪心算法不成立
int maxValue2(vector<vector<int>>& grid) {
	if(grid.size()==0)
		return 0;
	int sum = grid[0][0];
	int i=0,j=0;
	int rigt = grid.size()-1;
	int bottom = grid[0].size()-1;
	while(i!=rigt || j!=bottom){
		if(i<rigt&&j<bottom)
		{
			if(grid[i+1][j]>=grid[i][j+1])
			{
				sum += grid[i+1][j];
				i++;
			}
			else
			{
				sum += grid[i][j+1];
				j++;
			}
		}
		else if(i == rigt)
		{
			sum += grid[i][j+1];
			j++;
		}
		else if(j == bottom)
		{
			sum += grid[i+1][j];
			i++;
		}
	}
	return sum;
	
}
int maxValue(vector<vector<int>>& grid) {
	if(grid.size()==0)
		return 0;
	vector<vector<int>> sum(grid.size(),vector<int>(grid[0].size(),0));
	sum[0][0]=grid[0][0];
	for(int i=1;i<grid.size();i++)
		sum[i][0] = sum[i-1][0] + grid[i][0];
	for(int i=1;i<grid[0].size();i++)
		sum[0][i] = sum[0][i-1] + grid[0][i];
	for(int i=1;i<sum.size();i++)
		for(int j=1;j<sum[0].size();j++)
		{
			if(sum[i-1][j]>=sum[i][j-1])
				sum[i][j] = sum[i-1][j] + grid[i][j];
			else
				sum[i][j] = sum[i][j-1] + grid[i][j];
		}
 	return sum[sum.size()-1].back();	
}
int main() {
	vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
	cout<<maxValue(grid);
	return 0;
}

