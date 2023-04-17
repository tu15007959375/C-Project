#include"util.h"

int lengthOfLongestSubstring(string s) {
	unordered_map<char,int> m;
	int res=0,temp=0;
	for(int i=0;i<s.size();++i){
		temp=(m.count(s[i])==0)?temp+1:min(temp+1,i-m[s[i]]);
		m[s[i]]=i;
		res=max(temp,res);
	}
	return res;
}
int main() {
	string s = "abcabcbb";
	cout<<lengthOfLongestSubstring(s);
	return 0;
}

