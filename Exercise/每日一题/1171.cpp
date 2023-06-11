#include "util.h"



ListNode* removeZeroSumSublists(ListNode* head) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	int prefix = 0;
	unordered_map<int, ListNode*> seen;
	for (ListNode* node = dummy; node; node = node->next) {
		prefix += node->val;
		seen[prefix] = node;
	}
	prefix = 0;
	for (ListNode* node = dummy; node; node = node->next) {
		prefix += node->val;
		node->next = seen[prefix]->next;
	}
	return dummy->next;
}
int main()
{
	ListNode *head = creatLinkList({1,2,-3,3,1});
	ListNode *res = removeZeroSumSublists(head);
	printLinkList(res);
	return 0;
}
