#include"util.h"

string reverseWords(string s) {
	if(s.size()==0)
		return "";
	s.erase(0,s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ")+1);
	string res = "";
	while(s.size()){
		int pos = s.find_last_of(" ");
		if(pos!=-1)
		{
			res += s.substr(pos+1,s.size()-pos);
			s.erase(pos);
			s.erase(s.find_last_not_of(" ")+1);
			res += " ";
		}
		else
		{
			res += s;
			s = "";
			break;
		}
	}
	return res;
}
int main() {

	cout<<reverseWords("a good   example");
	return 0;
}

