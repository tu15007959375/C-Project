#include"util.h"

char firstUniqChar(string s) {
	if(s == ""||s == " ")
		return ' ';
	map<char,int> cmap;
	for(char x:s)
	{
		if(cmap.count(x)==0)
			cmap[x]=0;
		else
			cmap[x]++;
	}
	for(char x:s)
	{
		if(cmap[x]==0)
			return x;
	}
	return ' ';
}

int main() {
	cout<<firstUniqChar("abaccdeff");
	return 0;
}

