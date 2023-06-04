#include"util.h"
vector<vector<int>> allPath;

vector<int> path;

void findpath(TreeNode *node,int last)
{
	if(node == NULL)
		return;
	path.push_back(node->val);
	last -=node->val;
	if(last == 0 && node->left==NULL &&node->right == NULL)
		allPath.push_back(path);
	findpath(node->left,last);
	findpath(node->right,last);
	path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int target) {
	findpath(root,target);
	return allPath;
}

int main() {
	int target = 22;
	vector<int> rootvec = {0,5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1};
	TreeNode *root;
	createTree(root,rootvec,1);
	vector<vector<int>> Path = pathSum(root,target);
	for(vector tmp:Path)
		for(int x:tmp)
			cout<<x<<"\t";
	return 0;
}

