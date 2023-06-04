#include"util.h"

int findNthDigit(int n) {
	int i=1;//分段 第1段开始 
	
	while(n > 9*pow(10,i-1) *i)//找到n在第几段 ，如第二段有90*2 个字符
	{
		n = n - 9*pow(10,i-1) *i;
		i++;
	}
	//到这里已经知道是第几段i。 且是这一段的第几个字符
	
	int min_num = pow(10,i-1);//这一段的最小值。比如第二段，最小为10
	int cur_num = min_num + (n-1)/i;//知道是属于哪个数字 每个数字长度为i  第0数字是它本身
	int cur_bit = (n-1)%i;//看是这个数字的第几位，第0位为最高位，第1位为次高位。
	
	string s = to_string(cur_num);
	return   s[cur_bit]-'0';//返回这一位的数字
}		

int main() {
	cout<<findNthDigit(2147483647);
	return 0;
}

