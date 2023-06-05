#include"util.h"

int maxDepth(TreeNode* root) {
	if(!root)
		return 0;
	int leftd = maxDepth(root->left);
	int righd = maxDepth(root->right);
	return leftd>righd?leftd+1:righd+1;
}

int main() {
	TreeNode *root;
	createTree(root,{0,3,1,4,-1,2,-1,-1},1);
	cout<<maxDepth(root);
	return 0;
}

