#include"util.h"

vector<vector<int>> levelOrder(TreeNode* root) {
	if(!root)
		return {};
	queue<TreeNode*> q;
	vector<vector<int>> x;
	q.push(root);
	bool flag = true;
	while(!q.empty()){
		vector<int> tmpvec;
		int size = q.size();
		
		for(int i=0;i<size;i++)
		{
			TreeNode *tmp = q.front();
			q.pop();
			tmpvec.push_back(tmp->val);
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
		if(flag)
			x.push_back(tmpvec);
		else
		{
			reverse(tmpvec.begin(),tmpvec.end());
			x.push_back(tmpvec);
		}
		flag = !flag;
		
	}
	return x;
}
int main() {
	TreeNode *root;
	createTree(root,{0,3,9,20,-1,-1,15,7},1);
	vector<vector<int>> x = levelOrder(root);
	for(vector tmpvec:x)
	{
		for(int tmp:tmpvec)
			cout<<tmp<<"\t";
		cout<<"\n";
	}
	return 0;
}

