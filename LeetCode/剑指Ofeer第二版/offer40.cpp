#include"util.h"

//冒泡排序超时
//vector<int> getLeastNumbers(vector<int>& arr, int k) {
//	vector<int> res;
//	int size = arr.size();
//	if(size==0)
//		return {};
//	for(int i=0;i<k;i++)
//	{
//		for(int j=0;j<arr.size()-1;j++)
//		{
//			if(arr[j]<arr[j+1])
//				swap(arr[j],arr[j+1]);
//		}
//	}
//	size--;
//	for(int i=0;i<k;i++)
//		res.push_back(arr[size--]);
//	return res;
//}
void quicksort(vector<int>& arr,int l,int r)
{
	
}
vector<int> getLeastNumbers(vector<int>& arr, int k) {
	
	
}
int main() {
	vector<int> arr={4,5,1,6,2,7,3,8};
	vector<int> res = getLeastNumbers(arr,4);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}

