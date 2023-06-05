#include"util.h"
class Node {
public:
	int val;
	Node* left;
	Node* right;
	
	Node() {}
	
	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}
	
	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
void preorder(vector<Node*> &treelist,Node* root)
{
	if(root)
	{
		preorder(treelist,root->left);
		treelist.push_back(root);
		preorder(treelist,root->right);
	}		
}
Node* treeToDoublyList(Node* root) {
	if(!root)
		return NULL;
	vector<Node*> treelist;
	Node *head = new Node;
	preorder(treelist,root);
	if(treelist.size()==0)
		return head;
	head=treelist[0];
	for(int i=0;i<treelist.size()-1;i++)
	{
		treelist[i]->right=treelist[i+1];
		treelist[i+1]->left=treelist[i];
	}
	treelist[0]->left=treelist.back();
	treelist.back()->right=treelist[0];
	return head;
}

int main() {
	Node *root=new Node(4);
	Node *node1=new Node(2);
	Node *node2=new Node(5);
	Node *node3=new Node(1);
	Node *node4=new Node(3);
	root->left=node1;
	root->right=node2;
	root->left->left=node3;
	root->left->right=node4;
	Node *head = treeToDoublyList(root);
	return 0;
}

