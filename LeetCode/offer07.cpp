#include"util.h"

void findRoot(TreeNode* &x,vector<int> preorder, vector<int> inorder)
{
	if(!preorder.size()){
		x = NULL;
		return;
	}
	else
	{
		x = new TreeNode;
		x->val = preorder[0];
		if(preorder.size()==1){
			return;
		}
		int pos = distance(inorder.begin(),find(inorder.begin(),inorder.end(),x->val));
		findRoot(x->left,vector<int> (preorder.begin()+1,preorder.begin()+1+pos),vector<int> (inorder.begin(),inorder.begin()+pos));
		findRoot(x->right,vector<int> (preorder.begin()+1+pos,preorder.end()),vector<int> (inorder.begin()+1+pos,inorder.end()));
	}
	
	
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	
	TreeNode *head;
	findRoot(head,preorder,inorder);
	return head;
}

int main()
{
	vector<int> preorder={3,9,20,15,7};
	vector<int> inorder={9,3,15,20,7};

	TreeNode *head = buildTree(preorder,inorder);

	return 0; 
}

