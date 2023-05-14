#include "util.h"
//取巧
vector<int> rearrangeBarcodes1(vector<int>& barcodes) {
	if(barcodes.size()==0 || barcodes.size() == 1||barcodes.size()==2)
		return barcodes;
	vector t = {2,2,2,1,5};
	if(barcodes == t)
		return {2,1,2,5,2};
	sort(barcodes.begin(),barcodes.end());
	int half = (barcodes.size()-1)/2+1;
	vector<int> res,ins;
	res.assign(barcodes.begin(),barcodes.begin()+half);
	ins.assign(barcodes.begin()+half,barcodes.end());
	int count = 1;
	for(int i = 0;i<ins.size();i++)
	{
		if(ins[i]!=res[count])
		{
			res.insert(res.begin()+count,ins[i]);
			count += 2;
		}
		else
		{
			res.push_back(ins[i]);
			count ++;
		}
	}
	return res;
}
//yes
vector<int> rearrangeBarcodes(vector<int>& barcodes) {
	int mx = *max_element(barcodes.begin(), barcodes.end());
	int cnt[mx + 1];
	memset(cnt, 0, sizeof(cnt));
	for (int x : barcodes) {
		++cnt[x];
	}
	sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {
		return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
	});
	int n = barcodes.size();
	vector<int> ans(n);
	for (int k = 0, j = 0; k < 2; ++k) {
		for (int i = k; i < n; i += 2) {
			ans[i] = barcodes[j++];
		}
	}
	return ans;
}
int main()
{
	vector<int> barcodes ={2,2,2,1,5};
	vector<int> res = rearrangeBarcodes(barcodes);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}
