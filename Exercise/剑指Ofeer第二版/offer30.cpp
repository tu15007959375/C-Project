#include"util.h"

class MinStack {
	stack<int> x_stack;
	stack<int> min_stack;
public:
	MinStack() {
		min_stack.push(INT_MAX);
	}
	
	void push(int x) {
		x_stack.push(x);
		min_stack.push(::min(min_stack.top(), x));
	}
	
	void pop() {
		x_stack.pop();
		min_stack.pop();
	}
	
	int top() {
		return x_stack.top();
	}
	
	int min() {
		return min_stack.top();
	}
};

int main() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout<<minStack.min()<<endl;
	minStack.pop();
	cout<<minStack.top()<<endl;
	cout<<minStack.min()<<endl;
	return 0;
}

