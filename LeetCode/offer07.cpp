#include"util.h"


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	TreeNode *head = new TreeNode;
	return head;
}

int main()
{
	vector preorder={3,9,20,15,7};
	vector inorder={9,3,15,20,7};
	TreeNode *head = buildTree(preorder,inorder);
	
	return 0; 
}

