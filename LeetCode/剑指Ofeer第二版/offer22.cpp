#include"util.h"


ListNode* getKthFromEnd(ListNode* head, int k) {
	if(head == NULL)
		return head;
	ListNode *p,*q;
	p=head;
	q=head;
	for(int i=0;i<k;i++)
		p = p->next;
	while(p){
		p=p->next;
		q=q->next;
	}
	return q;
}

int main()
{
	ListNode * head=creatLinkList({1,2,3,4,5});
	head = getKthFromEnd(head,2);
	printLinkList(head);
	return 0;
}

