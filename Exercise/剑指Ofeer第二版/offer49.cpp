#include"util.h"
//存在问题：超时，因为每个数都需要一直除以，导致耗费时间长
int nthUglyNumber2(int n) {
	int a = 0, b = 0, c = 0;
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
		dp[i] = min(min(n2, n3), n5);
		if(dp[i] == n2) a++;
		if(dp[i] == n3) b++;
		if(dp[i] == n5) c++;
	}
	return dp[n - 1];
}
int nthUglyNumber(int n) {
	int a = 0, b = 0, c = 0;
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
		dp[i] = min(min(n2, n3), n5);
		if(dp[i] == n2) a++;
		if(dp[i] == n3) b++;
		if(dp[i] == n5) c++;
	}
	return dp[n - 1];
}

int main() {
	cout<<nthUglyNumber(1407);
	return 0;
}

