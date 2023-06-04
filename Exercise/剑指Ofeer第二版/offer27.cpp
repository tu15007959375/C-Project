#include"util.h"

void swapNode(TreeNode *&A,TreeNode *&B)
{
	TreeNode *tmp = A;
	A = B;
	B = tmp;
}
void swapTree(TreeNode *&root)
{
	if(root->left)
		swapTree(root->left);
	if(root->right)
		swapTree(root->right);
	if(root)
		swapNode(root->left,root->right);
}
TreeNode* mirrorTree(TreeNode* root) {
	if(root)
		swapTree(root);
	return root;
}
//更加好的递归解法
TreeNode* mirrorTree2(TreeNode* root) {
	if (root == NULL)
		return NULL;
	
	TreeNode* left = mirrorTree2(root->left);
	TreeNode* right = mirrorTree2(root->right);
	
	root->left = right;
	root->right = left;
	
	return root;
}
int main()
{
	TreeNode *A = new TreeNode;
	createTree(A,{0,3,4,5,1,2},1);//层次遍历建立二叉树
	A = mirrorTree2(A);
	printTree(A);
	return 0;
}

