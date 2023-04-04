#include"util.h"

vector<vector<int>> pathSum(TreeNode* root, int target) {
	return {};
}

int main() {
	int target = 22;
	vector<int> rootvec = {0,5,4,8,11,-1,13,4,7,2,1,1,5,1};
	TreeNode *root;
	createTree(root,rootvec,1);
	vector<vector<int>> path = pathSum(root,target);
	
	return 0;
}

