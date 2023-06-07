#include "util.h"

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
	int ans = 0;
	int n = reward1.size();
	vector<int> diffs(n);
	for (int i = 0; i < n; i++) {
		ans += reward2[i];
		diffs[i] = reward1[i] - reward2[i];
	}
	sort(diffs.begin(), diffs.end());
	for (int i = 1; i <= k; i++) {
		ans += diffs[n - i];
	}
	return ans;
}
int main()
{
	vector<int> reward1 = {1,4,4,6,4};
	vector<int> reward2 = {6,5,3,6,1};
	cout<<miceAndCheese(reward1, reward2, 1);
	return 0;
}
