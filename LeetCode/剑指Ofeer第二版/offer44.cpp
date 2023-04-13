#include"util.h"

int findNthDigit(int n) {
	map<int,int> countmap;
	map<int,int>::iterator iter;
	int sum = 0;
	int i=0;
	while(sum<n){
		int tmp = 9*pow(10,i);
		countmap[i]=tmp;
		sum += tmp;
		i++;
	}
	iter = --countmap.end();
	cout<<iter->first<<"\t"<<iter->second<<"\t";
	return 0;
}

int main() {
	cout<<findNthDigit(200);
	return 0;
}

