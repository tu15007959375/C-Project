#include "util.h"

bool haveConflict(vector<string>& event1, vector<string>& event2) {
	vector<int> res1;
	for(int i=0;i<4;i++)
	{
		string x;
		if(i<2)
			x = event1[i];
		else
			x = event2[i-2];
		int pos = x.find(":");
		int res = stoi(x.substr(0,pos))*100+stoi(x.substr(pos+1));
		res1.push_back(res);
	}
	if(res1[1]<res1[2]||res1[3]<res1[0])
		return false;
	else
		return true;
}
int main()
{
	vector<string> event1 = {"01:00","02:00"};
	vector<string> event2 = {"01:20","03:00"};
	cout<<haveConflict(event1,event2);
}
