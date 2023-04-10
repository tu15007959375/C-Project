#include"util.h"
class Codec {
public:
	
	string levelorder(TreeNode *root)
	{
		if(!root)
			return "";
		queue<TreeNode *> q;
		vector<int> valvec;
		string serializestr="";
		q.push(root);
		while(!q.empty()){
			TreeNode *tmp=q.front();
			q.pop();
			if(tmp)
			{
				valvec.push_back(tmp->val);
				q.push(tmp->left);
				q.push(tmp->right);
			}
			else
			{
				valvec.push_back(1001);
			}
		}
		int i=valvec.size()-1;
		while(valvec[i]==1001)
		{
			valvec.pop_back();
			i--;
		}
		for(int i=0;i<valvec.size();i++)
			serializestr += to_string(valvec[i])+",";
		return serializestr;
	}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string serializestr=levelorder(root);
		return serializestr;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if(data=="")
			return NULL;
		vector<int> valvec;
		queue<TreeNode *> q;
	
		int pos,i=1;
		while(data.size()!=0||data.find(",")!=-1){
			pos = data.find(",");
			string tmp = data.substr(0,pos);
			valvec.push_back(stoi(tmp));
			data.erase(0,pos+1);
		}
		TreeNode * root=new TreeNode(valvec[0]);
		q.push(root);
		while(!q.empty()){
			if(i>valvec.size()-1)
				break;
			TreeNode *tmpnode = q.front();
			q.pop();
			if(valvec[i]!=1001)
			{
				tmpnode->left=new TreeNode(valvec[i]);
				q.push(tmpnode->left);
			}
			i++;
			if(i<valvec.size()&&valvec[i]!=1001)
			{
				tmpnode->right=new TreeNode(valvec[i]);
				q.push(tmpnode->right);
			}
			i++;
		}
		
		return root;
	}
};

int main() {
	TreeNode *root;
	createTree(root,{0,1,2},1);
	Codec ser, deser;
	cout<<endl;
	TreeNode* ans = deser.deserialize(ser.serialize(root));
	printTree(ans);
	return 0;
}

