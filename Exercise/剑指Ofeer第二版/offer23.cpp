#include"util.h"


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *l3 = new ListNode;
	ListNode *p=l3;
	l3->val = 0;
	l3->next = NULL;
	if(!l1)
		return l2;
	if(!l2)
		return l1;
	while(l1 && l2){
		ListNode *tmp = new ListNode;
		tmp->next = NULL;
		if(l1->val <= l2->val)
		{
			tmp->val = l1->val;
			l1 = l1->next;
		}
		else
		{
			tmp->val = l2->val;
			l2 = l2->next;
		}
		p->next = tmp;
		p=p->next;
	}
	if(l1)
	{
		p->next = l1;
	}
	if(l2)
	{
		p->next = l2;
	}
	return l3->next;
}

int main()
{
	ListNode * head1=creatLinkList({1,2,4});
	ListNode * head2=creatLinkList({1,3,4});
	head1 = mergeTwoLists(head1,head2);
	printLinkList(head1);
	return 0;
}

