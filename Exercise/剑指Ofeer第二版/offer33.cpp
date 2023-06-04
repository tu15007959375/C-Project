#include"util.h"

int findpos(vector<int> postorder)
{
	if(postorder.empty()||postorder.size()==1)
		return -1;
	int size = postorder.size();
	int root = postorder[size-1];
	int pos=-1;
	int i=0;
	while(i<size){
		if(postorder[i]>root)
		{
			pos = i;
			break;
		}
		else
			i++;
	}
	return pos;
}
bool isacord(vector<int> left,vector<int> right,int root)
{
	bool flag = true;
	bool flag2=true;
	bool flag3=true;
	for(int tmp:left)
	{
		if(tmp>=root)
		{
			flag = false;break;
		}
	}
	for(int tmp:right)
	{
		if(tmp<=root)
		{
			flag = false;break;
		}
	}
	if(left.size()>1)
	{
		int pos = findpos(left);
		if(pos>0)
		{
			flag2 =  isacord(vector<int>(left.begin(),left.begin()+pos),vector<int>(left.begin()+pos,left.end()-1),left.back());
		}
		else if(pos ==0)
			flag2  = isacord(vector<int>(),vector<int>(left.begin(),left.end()-1),left.back());
		else
		{
			flag2 =  isacord(vector<int>(left.begin(),left.end()-1),vector<int>(),left.back());
		}
	}
	if(right.size()>1)
	{
		int pos1 = findpos(right);
		if(pos1>0)
		{
			flag3 =  isacord(vector<int>(right.begin(),right.begin()+pos1),vector<int>(right.begin()+pos1,right.end()-1),right.back());
		}
		else if(pos1 ==0)
			flag3  = isacord(vector<int>(),vector<int>(right.begin(),right.end()-1),right.back());
		else
		{
			flag3 =  isacord(vector<int>(right.begin(),right.end()-1),vector<int>(),right.back());
		}
	}
	return flag&&flag2&&flag3;
}
//注意事项
//1.左侧的大小不需要比较
//2.只需要传递int i,j就行，不需要传递vector
bool verifyPostorder(vector<int>& postorder) {
	if(postorder.empty()||postorder.size()==1)
		return true;
	int size = postorder.size();
	int root = postorder[size-1];
	int pos=findpos(postorder);
	if(pos>0)
	{
		vector<int> left(postorder.begin(),postorder.begin()+pos);
		vector<int> right(postorder.begin()+pos,postorder.end()-1);
		return isacord(left,right,root);
	}
	else if(pos ==0)
		return isacord(vector<int>(),vector<int>(postorder.begin(),postorder.end()-1),root);
	else
	{
		return isacord(vector<int>(postorder.begin(),postorder.end()-1),vector<int>(),root);
	}
}
bool verifyOrder(vector<int>& postorder, int l, int r) {
	if (l >= r) return true;
	int i;
	for (i = r; i >= l; i--) {
		if (postorder[i] < postorder[r]) break;
	}
	for (int j = i; j >= l; j--) {
		if (postorder[j] > postorder[r]) return false;
	}
	return verifyOrder(postorder, l, i) && verifyOrder(postorder, i + 1, r - 1);
}
bool verifyPostorder1(vector<int>& postorder) {
	return verifyOrder(postorder, 0, postorder.size() - 1);
}

int main() {
	vector<int> postorder = {5,4,3,2,1};
	cout<<verifyPostorder1(postorder);
	return 0;
}

