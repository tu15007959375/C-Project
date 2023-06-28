#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
void printinfo(int pos)
{
	if(pos == 0)
		cout<<"W";
	else if(pos == 1)
		cout<<"T";
	else
		cout<<"L";
	cout<<" ";
}
int main() {
	vector<double> game1,game2,game3;
	double tmp;
	int pos1,pos2,pos3;
	double max1,max2,max3;
	for(int i =0;i<3;i++)
	{
		cin>>tmp;
		game1.emplace_back(tmp);
	}
	for(int i =0;i<3;i++)
	{
		cin>>tmp;
		game2.emplace_back(tmp);
	}
	for(int i =0;i<3;i++)
	{
		cin>>tmp;
		game3.emplace_back(tmp);
	}
	pos1 = max_element(game1.begin(),game1.end())-game1.begin();
	pos2 = max_element(game2.begin(),game2.end())-game2.begin();
	pos3 = max_element(game3.begin(),game3.end())-game3.begin();
	max1 = *max_element(game1.begin(),game1.end());
	max2 = *max_element(game2.begin(),game2.end());
	max3 = *max_element(game3.begin(),game3.end());
	printinfo(pos1);
	printinfo(pos2);
	printinfo(pos3);
	double res = (max1*max2*max3*0.65-1)*2;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<res;
	return 0;
}
