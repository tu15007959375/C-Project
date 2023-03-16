#include"util.h"

int minArray(vector<int>& numbers) {
	if(numbers.size()==1)
		return numbers[0];
	int i=0;
	int j=numbers.size() - 1;
	
	while(i < j){
		int m = (i+j)/2;
		if(numbers[j]>numbers[m])
			j=m;
		else if(numbers[j]<numbers[m])
			i=m+1;
		else
			j--;
	}
	return numbers[i];
}
int main()
{
	vector<int> numbers = {3,4,5,1,2};

	cout<<minArray(numbers);
	return 0; 
}

