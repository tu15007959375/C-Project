#include "util.h"
bool cmp(const pair<int, int> a, const pair<int, int> b) {
	return a.first>b.first;//自定义的比较函数
}
int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
	if(values.size()==0)
		return 0;
	vector<pair<int,int>> vlvec;
	map<int,int> countmap;
	int res = 0;
	for(int i = 0;i<values.size();i++)
		vlvec.emplace_back(values[i],labels[i]);
	sort(vlvec.begin(),vlvec.end(),cmp);
	int i  = 0;
	int j = 0;
	while(i<numWanted)
	{
		if(j==labels.size())
			return res;
		if(countmap[vlvec[j].second]<useLimit)
		{
			res += vlvec[j].first;
			countmap[vlvec[j].second]++;
			i++;
			j++;
		}
		else
			j++;
			
	}
	return res;
}



int main()
{
	vector<int> values = {9,8,8,7,6};
	vector<int> labels = {0,0,0,1,1};
	int num = 3;
	int user = 2;
	cout<<largestValsFromLabels(values,labels,num,user);
	return 0;
}
