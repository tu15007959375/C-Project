#include "util.h"

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
	set<char> orset = {'a','e','i','o','u'};
	vector<int> wordcount(words.size()+1,0);
	
	wordcount[0] = 0;
	vector<int> res;
	for(int i = 1; i<=words.size(); i++)
	{
		wordcount[i] = wordcount[i-1];
		if(orset.find(words[i-1][0])!=orset.end()&&orset.find(words[i-1].back())!=orset.end())
			 wordcount[i]++;
	}

	for(vector<int> x:queries)
	{
		res.push_back(wordcount[x[1]+1]-wordcount[x[0]]);
	}
	return res;
}
int main()
{
	vector<string> words = {"aba","bcb","ece","aa","e"};
	vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
	vector<int> res = vowelStrings(words, queries);
	for(int x: res)
		cout<<x<<"\t";
	return 0;
}
