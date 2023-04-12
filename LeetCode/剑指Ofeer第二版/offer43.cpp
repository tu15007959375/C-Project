#include"util.h"
/*
  按照每一位的数字0~9的情况 划分该位前的高位和该位后的低位，
  看此位不变其他位的上限，依次递推获得每位累加每位的答案
  下面是每位的情况：
  1. 当前十位0（digit = 10）：
  （2304）含1位有0010~2219，发现十位始终为1时，高位和低位的数递增且跨越的范围仅受高位影响且为该位的答案
  000~229一共230个数 即为high * digit
  2. 当前十位1（digit = 10）:
  (2314) 含1位0010~2314， 此时高位低位组合数跨越范围受高位低位一起影响
  000~234一共235个数 即为high* digit + low + 1
  3. 当前十位2~9（digit = 10）:
  (2384) 含1位0010~2319， 此时高位低位组合数跨越范围仅受高位影响
  000~239一共249个数 即为(high + 1)*digit
 */
int countDigitOne(int n) {
	int high = n / 10, cur = n % 10, low = 0;
	long long res = 0, digit = 1;//digit最后两个样例会溢出需用long long声明
	//当前位cur还有值时会变成高位仍可能影响答案
	while(high || cur)
	{
		if(cur == 0) res += high * digit;
		else if(cur == 1) res += high * digit + low + 1;
		else res += (high + 1)* digit;
		//更新当前位及低位划分
		digit *= 10;
		cur = high % 10;
		high /= 10;
		low = n % digit;
	}
	return res;
}

int main() {
	cout<<countDigitOne(12);
	return 0;
}

