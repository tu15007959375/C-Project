#include"util.h"


bool isMatch(string s, string p) {
	int slen = s.length();
	int plen = p.length();
	int i = 0;
	bool flag = true;
	int j = 0;
	while(i<slen){
		if(s[i] == p[i])
		{
			i++;
			j++;
		}
	}
	return flag;
}
int main()
{
	string x= "aaa";
	cout<<x[4]<<endl;
	cout<<isMatch("aaa","aaa");	
	return 0;
}

