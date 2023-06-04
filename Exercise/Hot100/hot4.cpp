#include "util.h"

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if(nums1.size()==0&&nums2.size()==0)
		return 0;
	else if(nums1.size()==0)
	{
		if(nums2.size()%2)
			return nums2[(nums2.size()-1)/2];
		else 
			return ((double)nums2[(nums2.size()-1)/2]+nums2[(nums2.size()-1)/2+1])/2;
	}
	else if(nums2.size()==0)
	{
		if(nums1.size()%2)
			return nums1[(nums1.size()-1)/2];
		else 
			return ((double)nums1[(nums1.size()-1)/2]+nums1[(nums1.size()-1)/2+1])/2;
	}
	vector<int> merge;
	int pos = (nums1.size()+nums2.size()-1)/2;
	int count = (nums1.size()+nums2.size())/2+1;
	int left = 0;
	int right = 0;
	for(int i=0;i<count;i++)
	{
		if((left<=nums1.size()-1)&&(right<=nums2.size()-1))
		{
			if(nums1[left]>nums2[right])
			{
				merge.push_back(nums2[right]);
				right++;
			}
			else if(nums1[left]<=nums2[right])
			{
				merge.push_back(nums1[left]);
				left++;
			}
		}
		else if(left<=nums1.size()-1)
		{
			merge.push_back(nums1[left]);
			left++;
		}
		else{
			merge.push_back(nums2[right]);
			right++;
		}
	}
	if((nums1.size()+nums2.size())%2)
		return merge[pos];
	else
		return ((double)merge[pos]+merge[pos+1])/2;
	
}
int main()
{
	vector<int> nums1 = {1};
	vector<int> nums2 = {1};
	cout<<findMedianSortedArrays(nums1,nums2);
	return 0;
}
