#include "util.h"
bool isNum(string x)
{
	for(char tmp:x)
	{
		if(!isdigit(tmp))
			return false;
	}
	return true;
}
int maximumValue(vector<string> &strs) {
	int maxres = 0;
	for(string x:strs)
	{
		if(isNum(x))
		{
			maxres = max(maxres,stoi(x));
		}
		else
		{
			maxres = max(maxres,(int)x.size());
		}
	}
	return maxres;
}
int main()
{
	vector<string> strs = {"alic3","bob","3","4","00000"};
	cout<<maximumValue(strs);
	return 0;
}
