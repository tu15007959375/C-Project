#include "util.h"

int smallnum(string s)
{
	int res = 0;
	char now = 'z';
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]<now)
		{
			now = s[i];
			res = 1;
		}
		else if(s[i] == now)
			res++;
	}
	return res;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
	vector<int> wordscount;
	vector<int> res;
	for(string x:words)
		wordscount.emplace_back(smallnum(x));
	sort(wordscount.begin(),wordscount.end());
	for(string x:queries)
	{
		int tmp = smallnum(x);
		res.emplace_back(wordscount.end()-upper_bound(wordscount.begin(),wordscount.end(),tmp));
	}
	return res;
}
int main()
{
	vector<string> queries = {"cbd"};
	vector<string> words = {"zaaaz"};
	vector<int> res = numSmallerByFrequency(queries,words);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}
