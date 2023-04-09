#include"util.h"
class Codec {
public:
	
	string levelorder(TreeNode *root)
	{
		if(!root)
			return "";
		queue<TreeNode *> q;
		string serializestr="";
		q.push(root);
		while(!q.empty()){
			TreeNode *tmp=q.front();
			q.pop();
			if(tmp)
			{
				serializestr +=to_string(tmp->val);
				q.push(tmp->left);
				q.push(tmp->right);
			}
			else
			{
				serializestr +=" ";
			}
		}
		return serializestr;
	}
	TreeNode *createTree(string data,int i)
	{
		if(i>data.size()-1||data[i]== ' ')
			return NULL;
		TreeNode *root=new TreeNode(data[i]-'0');
		root->left=createTree(data,2*i);
		root->right=createTree(data,2*i+1);
		return root;
		
	}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string serializestr=levelorder(root);
		serializestr.erase(serializestr.find_last_not_of(" ")+1);
		return serializestr;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if(data=="")
			return NULL;
		data = " "+data;
		TreeNode * root = createTree(data,1);
		return root;
	}
};

int main() {
	TreeNode *root;
//	createTree(root,{0,1,2,3,-1,-1,4,5},1);
	createTree(root,{0,1},1);
	Codec ser, deser;
	TreeNode* ans = deser.deserialize(ser.serialize(root));
	printTree(ans);
	return 0;
}

