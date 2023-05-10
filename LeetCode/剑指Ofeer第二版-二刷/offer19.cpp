#include"util.h"

bool isMatch(string s, string p) {
	int m = s.size()+1;
	int n = p.size()+1;
	vector<vector<bool>> dp(m,vector<bool>(n,false));
	dp[0][0] = true;
	for(int i = 2;i<n;i+=2)
		dp[0][i] = dp[0][i-1]&&p[i-1] == '*';
	for(int i =1;i<m;i++)
		for(int j = 1;j<n;j++)
		{
			dp[i][j] = p[j - 1] == '*' ?
			dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'):
			dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
		}
	return dp[m-1][n-1];
}

int main()
{
	cout<<isMatch("aa","a*");
	return 0; 
}

