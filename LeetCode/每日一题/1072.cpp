#include "util.h"

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
	if(matrix.size()==0||matrix[0].size()==0)
		return 0;
	if(matrix[0].size()==1)
		return matrix.size();
	int commonres=0;
	for(int i = matrix.size()-1;i>=0;i--)
	{
		if(equal(matrix[i].begin()+1,matrix[i].end(),matrix[i].begin()))
		{
			matrix.erase(matrix.begin()+i);
			commonres++;
		}
	}
	vector<string> res;
	map<string,int> resmap;
	for(int i = 0;i<matrix.size();i++)
	{
		string res1;
		string res2;
		for(int j = 0;j<matrix[0].size();j++)
		{
			if(matrix[i][j]==1)
				res1 += j;
			else
				res2 += j;
		}
		if(res1[0]<=res2[0])
			res.push_back(res1);
		else
			res.push_back(res2);
	}
	for(string x:res)
	{
		if(resmap.count(x)==0)
			resmap[x] = 1;
		else
			resmap[x] ++;
	}
	auto i= max_element(resmap.begin(),resmap.end(),[](pair<string, int> left, pair<string,int> right) { return left.second < right.second; }); 
	return max(i->second,commonres);

}

int main()
{
	vector<vector<int>> matrix = {{0},{1},{0},{0},{1},{1},{1},{1},{0},{1}};
	cout<<maxEqualRowsAfterFlips(matrix);
	return 0;
}
