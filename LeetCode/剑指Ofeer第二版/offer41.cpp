#include"util.h"
//自己的版本
class MedianFinder {
public:
	vector<double> nums;
	/** initialize your data structure here. */
	MedianFinder() {
		
	}
	
	void addNum(int num) {
		if(nums.size()==0)
			nums.push_back(num);
		else
		{
			nums.insert(lower_bound(nums.begin(),nums.end(),num),num);
		}

	}
	
	double findMedian() {
		if(nums.size()==0)
			return NULL;
		int half = nums.size()/2;
		if(nums.size()%2)
			return nums[half];
		else
			return (nums[half-1]+nums[half])/2;
	}
};
//题解版本
class MedianFinder2 {
public:
	// 最大堆，存储左边一半的数据，堆顶为最大值
	priority_queue<int, vector<int>, less<int>> maxHeap;
	// 最小堆， 存储右边一半的数据，堆顶为最小值
	priority_queue<int, vector<int>, greater<int>> minHeap;
	/** initialize your data structure here. */
	MedianFinder() {
	}
	
	// 维持堆数据平衡，并保证左边堆的最大值小于或等于右边堆的最小值
	void addNum(int num) {
		/*
		 * 当两堆的数据个数相等时候，左边堆添加元素。
		 * 采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后
		 * 将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。
		 * 同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。
		 */
		if (maxHeap.size() == minHeap.size()) {
			minHeap.push(num);
			int top = minHeap.top();
			minHeap.pop();
			maxHeap.push(top);
		} else {
			maxHeap.push(num);
			int top = maxHeap.top();
			maxHeap.pop();
			minHeap.push(top);
		}
	}
	
	double findMedian() {
		if (maxHeap.size() == minHeap.size()) {
			return (maxHeap.top()+minHeap.top())*1.0/2;
		} else {
			return maxHeap.top()*1.0;
		}
	}
};
int main() {
	MedianFinder* media=new MedianFinder;
	media->addNum(1.0);
	media->addNum(2.0);
	cout<<media->findMedian();
	return 0;
}

