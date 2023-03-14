#include"util.h"

class CQueue {
public:
	stack<int> inStack, outStack;
	CQueue() {
		
	}
	void in2out() {
		while (!inStack.empty()) {
			outStack.push(inStack.top());
			inStack.pop();
		}
	}
	
	void appendTail(int value) {
		inStack.push(value);
	}
	
	int deleteHead() {
		if (outStack.empty()) {
			if (inStack.empty()) {
				return -1;
			}
			in2out();
		}
		int value = outStack.top();
		outStack.pop();
		return value;
	}
};

int main()
{
	CQueue cqueue;
	cqueue.appendTail(5);
	cqueue.appendTail(7);
	cqueue.deleteHead();


	return 0; 
}

