#include "util.h"

int maximumTastiness(vector<int>& price, int k) {
	sort(price.begin(), price.end());
	int l = 0, r = price.back() - price[0];
	auto check = [&](int x) -> bool {
		int cnt = 0, pre = -x;
		for (int& cur : price) {
			if (cur - pre >= x) {
				pre = cur;
				++cnt;
			}
		}
		return cnt >= k;
	};
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}
int main()
{
	vector<int> price = {13,5,1,8,21,2};
	cout<<maximumTastiness(price,3);
}
