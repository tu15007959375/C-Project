#include"util.h"
typedef struct Node {
	int val;
	Node *next;
	Node *random;
	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
}Node;

Node* copyRandomList(Node* head) {
	unordered_map<Node*,Node*> map;
	Node *p =head;
	while(p){
		Node *tmp = new Node(p->val);
		map[p]=tmp;
		p=p->next;
	}
	p=head;
	while(p){
		map[p]->next=map[p->next];
		map[p]->random=map[p->random];
		p=p->next;
	}
	return map[head];
}

int main() {
	Node *head=new Node(7);
	Node *node1=new Node(13);
	Node *node2=new Node(11);
	head->next=node1;
	node1->next=node2;
	node2->next=NULL;
	head->random=NULL;
	node1->random=node2;
	node2->random=head;
	Node *copyNode=copyRandomList(head);
	while(copyNode){
		cout<<"node"<<copyNode->val<<"\t";
		if(copyNode->random)
			cout<<"random"<<copyNode->random->val<<"\n";
		else
			cout<<"\n";
		copyNode=copyNode->next;
	}
	return 0;
}

