#include"util.h"


ListNode* reverseList(ListNode* head) {
	if(head == NULL||head->next == NULL)
		return head;
	ListNode *p = head->next;
	head->next = NULL;
	while(p){
		ListNode *tmp = new ListNode;
		tmp->val = p->val;
		tmp->next = head;
		head = tmp;
		p=p->next;
	}
	return head;
}

int main()
{
	ListNode * head=creatLinkList({1,2,4});
	head = reverseList(head);
	printLinkList(head);
	return 0;
}

