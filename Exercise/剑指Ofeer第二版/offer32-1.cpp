#include"util.h"

vector<int> levelOrder(TreeNode* root) {
	if(!root)
		return {};
	queue<TreeNode*> q;
	vector<int> x;
	q.push(root);
	while(!q.empty()){
		TreeNode *tmp = q.front();
		q.pop();
		x.push_back(tmp->val);
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}
	return x;
}
int main() {
	TreeNode *root;
	createTree(root,{0,3,9,20,-1,-1,15,7},1);
	vector<int> x = levelOrder(root);
	for(int tmp:x)
		cout<<tmp<<"\t";
	return 0;
}

