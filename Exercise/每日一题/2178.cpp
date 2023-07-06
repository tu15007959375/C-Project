#include "util.h"

vector<long long> maximumEvenSplit(long long finalSum) {
	if(finalSum%2>0)
		return {};
	vector<long long> res;
	for (int i = 2; i <= finalSum; i += 2) {
		res.push_back(i);
		finalSum -= i;
	}
	res.back() += finalSum;
	return res;
}
int main()
{
	vector<long long> res = maximumEvenSplit(28);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}
