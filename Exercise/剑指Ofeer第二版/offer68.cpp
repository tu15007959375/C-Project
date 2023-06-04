#include"util.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	while(root) {
		if ((p->val - root->val) * (q->val - root->val) <= 0) return root;
		else root = p->val > root->val ? root->right : root->left;
	}
	return root;
}

int main() {
	TreeNode *root;
	createTree(root,{0,6,2,8,0,4,7,9,-1,-1,3,5},1);
	TreeNode *p = new TreeNode(3);
	TreeNode *q = new TreeNode(5);
	TreeNode *res = lowestCommonAncestor(root,p,q);
//	cout<<res->val;
	return 0;
}

