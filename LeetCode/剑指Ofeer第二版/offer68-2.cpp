#include"util.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == nullptr || root == p || root == q) return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if(left == nullptr) return right;
	if(right == nullptr) return left;
	return root;
	
}

int main() {
	TreeNode *root;
	createTree(root,{0,3,5,1,6,2,0,8,-1,-1,7,4},1);
	TreeNode *p = new TreeNode(3);
	TreeNode *q = new TreeNode(5);
	TreeNode *res = lowestCommonAncestor(root,p,q);
//	cout<<res->val;
	return 0;
}

