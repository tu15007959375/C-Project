#include<iostream>
#include<vector>
#include<string> 
using namespace std;

string replaceSpace(string s) {
	string s1 = "";
	for(char tmp:s)
	{
		if(tmp == ' ')
		{
			s1 += "%20";
		}
		else
			s1 += tmp;
	}
	return s1;
}
int main()
{
	string s = "We are happy.";
	cout<<replaceSpace(s)<<endl;
	return 0; 
}

