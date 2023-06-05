#include"util.h"

bool validateStackSequences1(vector<int>& pushed, vector<int>& popped) {
	stack<int> test;
	bool flag = true;
	int size = pushed.size();
	if(size == 0)
		return true;
	if(size ==1)
		return pushed[0]==popped[0];
	int i = 0;
	int j = 0;
	while(j<size){
		if(pushed[i]!=popped[j])
		{
			test.push(pushed[i]);
			i++;
			if(i == size)
				return false;
		}
		else
		{
			if(test.size() == 0)
			{
				i++;
				j++;
			}
			else
			{
				++j;
				while(j<size&&test.top()==popped[j]){
					test.pop();
					j++;
					if(test.size() == 0)
						break;
				}
				if(test.size() != 0)
					if(test.top()!=popped[j]&&i==size-1)
						return false;
				if(i!=size-1)
					i++;
			}
		}
	}
	return flag;
}
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	stack<int> test;
	int size = pushed.size();
	if(size == 0)
		return true;
	if(size ==1)
		return pushed[0]==popped[0];
	int i=0;
	for(int x:pushed)
	{
		test.push(x);
		while(!test.empty()&&test.top()==popped[i]){
			test.pop();
			i++;
		}
	}
	return test.empty();
}
int main() {
	vector<int> pushed = {1,2,3,4,5};
	vector<int> popped = {4,5,3,2,1};
	cout<<validateStackSequences(pushed,popped);
	return 0;
}

