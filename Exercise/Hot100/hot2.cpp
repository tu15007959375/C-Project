#include "util.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *res= new ListNode;
	ListNode *p = res;
	int flag = 0;
	while(l1&&l2){
		int curval = l1->val + l2->val + flag;
		int tmp = curval %10;
		ListNode * curnode = new ListNode(tmp);
		flag = curval/10;
		p->next = curnode;
		p = p->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1){
		ListNode * curnode;
		int tmp = l1->val + flag;
		if(tmp==10)
		{
			curnode = new ListNode(0);
			flag = 1;
		}
		else
		{
			curnode = new ListNode(tmp);
			flag = 0;
		}
		p->next = curnode;
		p = p->next;
		l1 = l1->next;
	}
	while(l2){
		ListNode * curnode;
		int tmp = l2->val + flag;
		if(tmp==10)
		{
			curnode = new ListNode(0);
			flag = 1;
		}
		else
		{
			curnode = new ListNode(tmp);
			flag = 0;
		}
		p->next = curnode;
		p = p->next;
		l2 = l2->next;
	}
	if(flag == 1)
	{
		ListNode * curnode = new ListNode(1);
		p->next = curnode;
	}
	return res->next;
}
int main()
{
	ListNode *l1 = creatLinkList({3,7});
	ListNode *l2 = creatLinkList({9,2});
	ListNode *res = addTwoNumbers(l1,l2);
	printLinkList(res);

	return 0;
}
