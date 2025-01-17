#include"util.h"


vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.empty()) 
		return {};
	vector<int> res;
	int l = 0;                      //左边界
	int r = matrix[0].size() - 1;   //右边界
	int t = 0;                      //上边界
	int b = matrix.size() - 1;      //下边界
	while (true)
	{
		//left -> right
		for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);
		if (++t > b) break;
		//top -> bottom
		for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
		if (--r < l) break;
		//right -> left
		for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);
		if (--b < t) break;
		//bottom -> top
		for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
		if (++l > r) break;
	}
	return res;
}

int main() {
	vector<vector<int>> matrix =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> test = spiralOrder(matrix);
	return 0;
}

