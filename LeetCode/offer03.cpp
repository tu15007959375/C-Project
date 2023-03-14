#include"util.h"


int findRepeatNumber(vector<int>& nums) {
	unordered_map<int, bool> map;
    for(int num : nums) 
	{
        if(map[num]) return num;
            map[num] = true;
    }
    return -1;

}
int main()
{	
	vector<int> nums={1,4,6,7,2,4};
	cout<<findRepeatNumber(nums)<<endl;
	return 0; 
}

