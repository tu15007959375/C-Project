#include"util.h"

class MaxQueue {
public:
	queue<int> q;
	deque<int> d;
	MaxQueue() {
	}
	
	int max_value() {
		if(d.empty())
			return -1;
		return d.front();
	}
	
	void push_back(int value) {
		while(!d.empty()&&d.back()<value)
			d.pop_back();
		d.push_back(value);
		q.push(value);
	}
	
	int pop_front() {
		if(q.empty())
			return -1;
		int ans = q.front();
		if(ans==d.front())
			d.pop_front();
		q.pop();
		return ans;
	}
};
int main() {
	MaxQueue *maxq = new MaxQueue();
	maxq->push_back(6);
	maxq->push_back(10);
	cout<<maxq->max_value();
	
	return 0;
}

