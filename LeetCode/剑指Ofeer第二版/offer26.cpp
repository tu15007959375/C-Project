#include"util.h"
//自己写的有一个问题，就是在寻找A->val == val的时候，如果存在重复值，就需要使用循环再次寻找
//TreeNode *findsub(TreeNode *A,int val)
//{
//	if(!A)
//		return NULL;
//	if(A->val == val)
//		return A;
//	if(findsub(A->left,val))
//		return findsub(A->left,val);
//	else
//		return findsub(A->right,val);
//}
//bool issub(TreeNode *A, TreeNode *B)
//{
//	if(A==NULL&&B!=NULL)
//		return false;
//	if(A!=NULL&&B!=NULL)
//	{
//		if(A->val!=B->val)
//			return false;
//		else
//			return issub(A->left,B->left)&&issub(A->right,B->right);
//	}
//	return true;
//}
//bool isSubStructure(TreeNode *A, TreeNode *B) {
//	if(!B)
//		return false;
//	TreeNode *Atmp = findsub(A,B->val);
//	return issub(Atmp,B);
//}
//该代码为判断是否为相同树
//bool isSubStructure(TreeNode *A, TreeNode *B) {
//	if (!A && !B)
//		return true;
//	return A && B && A->val == B->val && (isSubStructure(A->left, B->left)) && (isSubStructure(A->right, B->right));
//}
bool isSameTree(TreeNode *A, TreeNode *B) {
	if (!A && !B)
		return true;
	if(A&&!B)
		return true;
	return A && B && A->val == B->val && (isSameTree(A->left, B->left)) && (isSameTree(A->right, B->right));
}
bool isSubStructure(TreeNode *A, TreeNode *B)
{
	if (!A || !B)
		return false;
	if (isSameTree(A, B))
		return true;
	return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}
int main()
{
	TreeNode *A = new TreeNode;
	TreeNode *B = new TreeNode;
	createTree(A,{0,3,4,5,1,2},1);//层次遍历建立二叉树
	createTree(B,{0,3,4,5},1);
	bool flag = isSubStructure(A,B);
	cout<<flag;
	return 0;
}

