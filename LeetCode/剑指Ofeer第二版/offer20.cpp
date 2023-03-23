#include"util.h"
typedef pair<char,int> charint;
typedef unordered_map<char,int> unmap;

bool isNumber(string s) {
	vector<unmap> states = {
		unmap{charint(' ',0),charint('s',1),charint('d',2),charint('.',4)},
		unmap{charint('d',2),charint('.',4)},
		unmap{charint('d',2),charint('.',3),charint('e',5),charint(' ',8)},
		unmap{charint('d',3),charint('e',5),charint(' ',8)},
		unmap{charint('d',3)},
		unmap{charint('s',6),charint('d',7)},
		unmap{charint('d',7)},
		unmap{charint('d',7),charint(' ',8)},
		unmap{charint(' ',8)}
	};
	int p = 0;
	char t;
	for(char c:s){
		if(c >= '0' && c <= '9')
			t = 'd';
		else if(c == '+' || c == '-')
			t = 's';
		else if(c == 'e' || c == 'E')
			t = 'e';
		else if(c == '.' || c == ' ')
			t = c;
		else
			t = '?';
		if(!states[p].count(t))
			return false;
		p = (int) states[p][t];
	}
	return p == 2 || p == 3 || p == 7 || p == 8;
}

int main()
{
	
	cout<<isNumber("  12e33  ");	
	return 0;
}

