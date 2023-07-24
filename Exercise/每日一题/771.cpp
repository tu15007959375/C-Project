#include "util.h"

int numJewelsInStones(string jewels, string stones) {
	set<char> jeset;
	int res = 0;
	for(char x:jewels)
		jeset.insert(x);
	for(char x:stones)
	{
		res+=jeset.count(x);
	}
	return res;
}
int main()
{
	
	cout<<numJewelsInStones("aA", "z");
	return 0;
}
