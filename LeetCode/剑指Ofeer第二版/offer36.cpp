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
void preorder(Node* root)
{
	
}
Node* treeToDoublyList(Node* root) {
	vector<Node*> treelist;
	
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

