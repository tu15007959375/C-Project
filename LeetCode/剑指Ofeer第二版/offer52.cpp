#include"util.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int lenA=0;
	int lenB=0;
	ListNode *p=headA;
	ListNode *q=headB;
	ListNode *res = NULL;
	while(p){
		lenA++;
		p=p->next;
	}
	while(q){
		lenB++;
		q=q->next;
	}
	if(lenA==0||lenB==0)
		return res;
	if(lenA>lenB)
	{
		for(int i=0;i<lenA-lenB;i++)
			headA = headA->next;
	}
	else if(lenB>lenA){
		for(int i=0;i<lenB-lenA;i++)
			headB = headB->next;
	}
	while(headA&&headB){
		if(headA==headB)
		{
			res = headA;
			break;
		}
		headA=headA->next;
		headB=headB->next;
	}
	return res;
}
int main() {
	ListNode *headA=creatLinkList({1,2});
	ListNode *headB=creatLinkList({2});
	ListNode *headC = creatLinkList({7,8,9});
	headA->next->next=headC;
	headB->next=headC;
	cout<<getIntersectionNode(headA,headB)->val;

	return 0;
}

