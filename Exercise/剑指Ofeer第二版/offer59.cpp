#include"util.h"

vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
	vector<int> res;
	int maxval = *max_element(nums.begin(),nums.begin()+k);
	int pos = max_element(nums.begin(),nums.begin()+k)-nums.begin();
	res.push_back(maxval);
	for(int i=1;i<nums.size()-k+1;i++)
	{
		if(pos != i-1 )
		{
			res.push_back(max(nums[pos],nums[i+k-1]));
			pos = nums[pos]>nums[i+k-1]?pos:i+k-1;
		}
		else
		{
			pos = max_element(nums.begin()+i,nums.begin()+i+k)-nums.begin();
			res.push_back(*max_element(nums.begin()+i,nums.begin()+i+k));
		}
	}
	return res;
}
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
	int n = nums.size();
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < k; ++i) {
		q.emplace(nums[i], i);
	}
	vector<int> ans = {q.top().first};
	for (int i = k; i < n; ++i) {
		q.emplace(nums[i], i);
		while (q.top().second <= i - k) {
			q.pop();
		}
		ans.push_back(q.top().first);
	}
	return ans;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	//判断特殊情况
	int n = nums.size();
	if(n < k || k <= 0) return {};
	//滑动窗口的前后指针
	int low =  1 - k,high = 0; 
	
	deque<int> dq;//双端队列
	vector<int> res;
	
	while(high < n){
		//判断滑窗的low端是否是最大的元素
		if(low >= 1 && nums[low - 1] == dq[0]) 
			dq.pop_front();
		
		while(!dq.empty() && dq[0] < nums[high]) 
			dq.pop_front();//小于nums[high]的元素出队
		while(!dq.empty() && dq[dq.size()-1] < nums[high]) 
			dq.pop_back();//小于nums[high]的元素出队
		
		//此时的high指针进队
		dq.push_back(nums[high]);
		
		if(low >= 0) 
			res.push_back(dq[0]);//当low >= 0，滑窗已经形成
		low ++;
		high ++;
	}
	return res;
}
int main() {

	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	vector<int> res = maxSlidingWindow(nums,3);
	for(int x: res)
		cout<<x<<"\t";
	return 0;
}

