#include"util.h"

string reverseLeftWords(string s, int n) {
	string top = s.substr(0,n);
	string bootm = s.substr(n,s.size()-n);
	return bootm+top;
}
int main() {

	cout<<reverseLeftWords("abcdefg",2);
	return 0;
}

