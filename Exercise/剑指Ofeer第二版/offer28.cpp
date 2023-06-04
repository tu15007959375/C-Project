#include"util.h"

bool leftandright(TreeNode *left,TreeNode *right)
{
	bool flag1 = false;
	if(!left && !right)
	{
		return true;
	}
	else if(left && right)
	{
		if(left->val == right->val)
			flag1 = true;
	}
	return flag1 && leftandright(left->left,right->right) && leftandright(left->right,right->left);
}

bool isSymmetric(TreeNode* root) {
	if(!root)
		return true;
	return leftandright(root->left,root->right);
}
int main()
{
	TreeNode *A = new TreeNode;
	createTree(A,{0,1,2,2,3,4,4,3},1);//层次遍历建立二叉树
	cout<<isSymmetric(A);
	return 0;
}

