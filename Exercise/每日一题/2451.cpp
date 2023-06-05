#include "util.h"

string oddString(vector<string>& words) {
	vector<vector<int>> res(words.size());
	if(words.size()==0)
		return "";
	if(words.size()==1)
		return words[0];
	int count = 0;
	for(string x:words)
	{
		for(int i=0;i<x.size()-1;i++)
		{
			res[count].push_back(x[i+1]-x[i]);
		}
		count++;
	}
	int i;
	for(i=0;i<res.size()-1;i++)
	{
		if(res[i]!=res[i+1])
			break;
	}
	if(i>=res.size()-1-i)
	{
		if(res[0]==res[i])
			return words[i+1];
		return words[i];
	}
	else
	{
		if(res[res.size()-1]==res[i])
			return words[i+1];
		return words[i];
	}
		
}
int main()
{
	vector<string> words = {"aaa","bob","ccc","ddd"};
	cout<<oddString(words);
}
