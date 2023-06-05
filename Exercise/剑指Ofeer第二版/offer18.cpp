#include"util.h"


ListNode* deleteNode(ListNode* head, int val) {
	if(head->val == val)
		return head->next;
	ListNode * pre = head;
	ListNode * now = head->next;
	while(now){
		if(now->val == val){
			pre->next = now->next;
			free(now);//在leetcode中不需要用free或deltte操作指针
			return head;
		}
		else{
			pre = now;
			now = now->next;
		}
	}
	return head;
}
int main()
{
	ListNode* head =creatLinkList({1,3,5,7,9});
	head = deleteNode(head, 3);
	printLinkList(head);
	
	return 0; 
}

