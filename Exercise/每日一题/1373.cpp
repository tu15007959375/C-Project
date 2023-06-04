#include "util.h"
//超时
vector<int> res;
void inorder(TreeNode * root)
{
	if(!root)
		return;
	inorder(root->left);
	res.push_back(root->val);
	inorder(root->right);
}
int getSum(TreeNode* root)
{
	int sum = 0;
	res.clear();
	inorder(root);
	for(int i = 0; i<res.size()-1; i++)
	{
		if(res[i]>=res[i+1])
			return -1;
		sum += res[i];
	}
	sum += res[res.size()-1];
	return sum;
}

int maxSumBST(TreeNode* root) {
	if(!root)
		return 0;
	queue<TreeNode*> q;
	int res = 0;
	q.push(root);
	while(!q.empty()){
		TreeNode *tmp = q.front();
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
		res = max(res,getSum(tmp));
		q.pop();
	}
	return res;
}


int ans = 0; // 二叉搜索树可以为空

tuple<int, int, int> dfs(TreeNode *node) {
	if (node == nullptr)
		return {INT_MAX, INT_MIN, 0};
	
	auto [l_min, l_max, l_sum] = dfs(node->left); // 递归左子树
	auto [r_min, r_max, r_sum] = dfs(node->right); // 递归右子树
	int x = node->val;
	if (x <= l_max || x >= r_min) // 不是二叉搜索树
		return {INT_MIN, INT_MAX, 0};
	
	int s = l_sum + r_sum + x; // 这棵子树的所有节点值之和
	ans = max(ans, s);
	
	return {min(l_min, x), max(r_max, x), s};
}
int maxSumBST1(TreeNode *root) {
	dfs(root);
	return ans;
}
int main()
{
	TreeNode *root;
	createTree(root,{0,1,4,3,2,4,2,5,-1,-1,-1,-1,-1,-1,4,6},1);
	cout<<maxSumBST1(root);
	return 0;
}
