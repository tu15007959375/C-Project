#include"util.h"


bool isSubStructure(TreeNode* A, TreeNode* B) {
	return false;
}

int main()
{
	TreeNode *A = new TreeNode;
	TreeNode *B = new TreeNode;
	createTree(A,{0,3,4,5,1,2},1);
	createTree(B,{0,4,1},1);
	bool flag = isSubStructure(A,B);
	cout<<flag;
	return 0;
}

