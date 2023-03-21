#include"util.h"


bool isMatch(string s, string p) {
	int m = s.size() + 1, n = p.size() + 1;
	vector<vector<bool>> dp(m, vector<bool>(n, false));
	dp[0][0] = true;
	for(int j = 2; j < n; j += 2)
		dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			dp[i][j] = p[j - 1] == '*' ?
			dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'):
			dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
		}
	}
	return dp[m - 1][n - 1];
}

int main()
{
	string x= "aaa";
	cout<<x[4]<<endl;
	cout<<isMatch("aaa","aaa");	
	return 0;
}

