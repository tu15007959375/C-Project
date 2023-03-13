#include"util.h"


vector<int> reversePrint(ListNode *head) 
{
	vector<int> list;
	ListNode *p =head;
	while(p){
		list.insert(list.begin(),p->val);
		p = p->next;
	}
	return list;
}

int main()
{
	vector<int> node = {1,2,3,7,8,54};
	ListNode *head = new ListNode;
	head = creatLinkList(node);
	
	vector<int> list = reversePrint(head);
	for(int x:list){
		cout<<x<<"  ";
	}
	return 0; 
}

