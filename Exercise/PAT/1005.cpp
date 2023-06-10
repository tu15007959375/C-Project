#include<iostream>
#include<vector>
using namespace std;

int main() {
	string engnums[10]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
	vector<string> outres;
	string s;
	cin>>s;
	int res = 0;
	if(s.size()==1&&s[0]=='0')
	{
		cout<<"zero";
		return 0;
	}
	for(int i = 0;i<s.size();i++)
		res += (s[i] - '0');
	while(res!=0){
		int tmp = res%10;
		outres.emplace(outres.begin(),engnums[tmp]);
		res /= 10;
	}
	for(int i = 0;i<outres.size()-1;i++)
		cout<<outres[i]<<" ";
	cout<<outres.back();
	return 0;
}

