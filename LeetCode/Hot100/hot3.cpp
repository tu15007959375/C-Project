#include "util.h"

int lengthOfLongestSubstring(string s) {
	if(s ==" ")
		return 1;
	unordered_map<char,int> umap;
	int res = 0;
	int start = 0;
	int end = 0;
	for(;end<s.size();end++)
	{
		if(umap.count(s[end])==0)
		{
			umap[s[end]] = end;
			res = max(res,end-start+1);
		}
		else
		{
			start = max(start,umap[s[end]]+1);
			umap[s[end]] = end;
			res = max(res,end-start+1);
		}
	}
	return res;

}
int main()
{
	cout<<lengthOfLongestSubstring("abba");
	return 0;
}
