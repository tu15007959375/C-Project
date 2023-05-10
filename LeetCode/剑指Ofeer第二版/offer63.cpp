#include"util.h"

int maxProfit(vector<int>& prices) {
	if(prices.size()==0||prices.size()==1)
		return 0;
	int minnum = prices[0];
	int res = 0;
	for(int i=1;i<prices.size();i++)
	{
		if(prices[i]-minnum>res)
			res = prices[i]-minnum;
		if(prices[i]<minnum)
			minnum = prices[i];
	}
	return res;
}
int main() {
	vector<int> prices = {7,6,4,3,1};
	cout<<maxProfit(prices);
	return 0;
}

