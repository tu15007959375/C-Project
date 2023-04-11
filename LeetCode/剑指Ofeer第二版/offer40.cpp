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
vector<int> quicksort(vector<int>& arr,int k,int l,int r)
{
	int i=l;
	int j=r;
	while(i<j){
		while(i<j&&arr[j]>=arr[l])
			j--;
		while(i<j&&arr[i]<=arr[l])
			i++;
		swap(arr[i],arr[j]);
	}
	swap(arr[i],arr[l]);
	if(i>k)
		return quicksort(arr,k,l,i-1);
	if(i<k)
		return quicksort(arr,k,i+1,r);
	vector<int> res;
	res.assign(arr.begin(),arr.begin()+k);
	return res;
}
vector<int> getLeastNumbers(vector<int>& arr, int k) {
	if(k>=arr.size())
		return arr;
	vector<int> res = quicksort(arr,k,0,arr.size()-1);
	return res;
}
int main() {
	vector<int> arr={0,1,2,1};
	vector<int> res = getLeastNumbers(arr,1);
	for(int x:res)
		cout<<x<<"\t";
	return 0;
}

