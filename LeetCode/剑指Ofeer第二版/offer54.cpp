#include"util.h"

vector<int> values;
void preorder(TreeNode* root)
{
	if(!root)
		return;
	preorder(root->left);
	values.push_back(root->val);
	preorder(root->right);
}
int kthLargest(TreeNode* root, int k) {
	if(!root)
		return NULL;
	preorder(root);
	return values[values.size()-k];
}
int main() {
	TreeNode *root;
	createTree(root,{0,3,1,4,-1,2,-1,-1},1);
	cout<<kthLargest(root,1);
	return 0;
}

