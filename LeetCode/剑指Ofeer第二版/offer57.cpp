#include"util.h"

vector<int> findres(int begin,int end,int target)
{
	vector<int> re;
	int sum=0;
	for(int i=begin;i<=end;i++)
	{
		re.push_back(i);
		sum += i;
		if(sum == target)
			return re;
		else if(sum > target)
			return {};
	}
	return {};
}
//暴力法
vector<vector<int>> findContinuousSequence1(int target) {
	if(target==0||target==1||target==2)
		return {{}};
	vector<vector<int>> res;
	int end = (target-1)/2+1;
	if(target%2==0)
		end--;
	int begin=1;
	while(begin!=end){
		vector<int> re = findres(begin,end,target);
		if(re.size())
			res.push_back(re);
		begin++;
	}
	return res;
}
int getsum(int begin,int end)
{
	return (begin+end)*(end-begin+1)/2;
}
//双指针法
vector<vector<int>> findContinuousSequence(int target) {
	if(target==0||target==1||target==2)
		return {{}};
	vector<vector<int>> res;
	int end = (target-1)/2+1;
	if(target%2==0)
		end--;
	int pos1 = 1;
	int pos2 = 2;
	while(pos2<=end){
		if(target>getsum(pos1,pos2))
			pos2++;
		else if(target<getsum(pos1,pos2))
			pos1++;
		else
		{
			vector<int> re;
			for(int i=pos1;i<=pos2;i++)
				re.push_back(i);
			res.push_back(re);
			pos1++;
			pos2++;
		}
	}
	return res;
}
int main() {

	vector<vector<int>> res = findContinuousSequence(15);
	for(vector x:res)
	{
		for(int tmp:x)
			cout<<tmp<<"\t";
		cout<<endl;
	}
	return 0;
}

