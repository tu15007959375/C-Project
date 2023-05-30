#include "util.h"

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
	unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
	vector<TreeNode *> roots;
	
	function<TreeNode *(TreeNode *, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode * {
		if (node == nullptr) {
			return nullptr;
		}
		bool deleted = to_delete_set.count(node->val) ? true : false;
		node->left = dfs(node->left, deleted);
		node->right = dfs(node->right, deleted);
		if (deleted) {
			return nullptr;
		} else {
			if (is_root) {
				roots.emplace_back(node);
			}
			return node;
		}
	};
	
	dfs(root, true);
	return roots;
	
}

int main()
{
	TreeNode *root;
	createTree(root,{0,1,2,3,4,5,6,7},1);
	vector<int> to_delete = {3,5};
	vector<TreeNode *> treevec = delNodes(root,to_delete);
	for(TreeNode *x:treevec)
		cout<<x->val<<"\t";
	return 0;
}
