#include "util.h"
struct Entry {
	int i, j, sum;
	Entry(int _i, int _j, int _sum): i(_i), j(_j), sum(_sum) {}
	bool operator< (const Entry& that) const {
		return sum > that.sum;
	}
};

vector<int> merge(const vector<int>& f, const vector<int>& g, int k) {
	if (g.size() > f.size()) {
		return merge(g, f, k);
	}
	
	priority_queue<Entry> q;
	for (int i = 0; i < g.size(); ++i) {
		q.emplace(0, i, f[0] + g[i]);
	}
	
	vector<int> ans;
	while (k && !q.empty()) {
		Entry entry = q.top();
		q.pop();
		ans.push_back(entry.sum);
		if (entry.i + 1 < f.size()) {
			q.emplace(entry.i + 1, entry.j, f[entry.i + 1] + g[entry.j]);
		}
		--k;
	}
	
	return ans;
}

int kthSmallest(vector<vector<int>>& mat, int k) {
	int m = mat.size();
	vector<int> prev = mat[0];
	for (int i = 1; i < m; ++i) {
		prev = move(merge(prev, mat[i], k));
	}
	return prev[k - 1];
}
int main()
{
	vector<vector<int>> mat ={{1,10,10},{1,4,5},{2,3,6}};
	cout<<kthSmallest(mat,9);
	return 0;
}
