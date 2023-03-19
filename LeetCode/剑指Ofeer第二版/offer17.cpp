#include"util.h"


vector<int> printNumbers(int n) {
	string x="";
	while(n){
		x += "9";
		n--;
	}
	int count = atoi(x.c_str());
	vector<int> li(count);
	iota(li.begin(),li.end(),1);
	return li;
}
//以下是大数解法
class Solution {
	vector<string> res;
	string cur;
	char NUM[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	
	// 生成长度为 len 的数字，正在确定第x位（从左往右）
	void dfs(int x, int len) {
		if(x == len) {
			res.push_back(cur);
			return;
		}
		int start = x==0? 1 : 0; // X=0表示左边第一位数字，不能为0
		for(int i=start; i<10; i++) {
			cur.push_back(NUM[i]); // 确定本位数字
			dfs(x+1, len); // 确定下一位数字
			cur.pop_back(); // 删除本位数字
		}
	}
public:
	vector<string> printNumbers(int n) {
		for(int i=1; i<=n; i++) // 数字长度：1~n
			dfs(0, i);
		return res;
	}
};
int main()
{
	vector<int> li = printNumbers(1);
	for(int x:li)
		cout<<x<<"  ";
	return 0; 
}

