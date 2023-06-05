#include"util.h"

int maxDepth(TreeNode* root) {
	if(!root)
		return 0;
	return max(maxDepth(root->left),maxDepth(root->right))+1;
}
bool isBalanced(TreeNode* root) {
	if(!root)
		return true;
	bool nowroot = false;
	int leftd = maxDepth(root->left);
	int righd = maxDepth(root->right);
	if(abs(leftd-righd)<=1)
		nowroot = true;
	return nowroot&&isBalanced(root->left)&&isBalanced(root->right);

}

int main() {
	TreeNode *root;
	createTree(root,{0,3,1,4,-1,2,-1,-1},1);
	cout<<isBalanced(root);
	return 0;
}

