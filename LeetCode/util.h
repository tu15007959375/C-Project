#include<vector>
#include<string> 
#include<iostream>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode *next;
}ListNode;

ListNode* creatLinkList(vector<int> list)
{
	ListNode *head = new ListNode;
	ListNode *p = head;
	p->val = list[0];
	ListNode *tmp;
	for(unsigned i=1;i<list.size();i++)
	{
		tmp = (ListNode *)malloc(sizeof(ListNode));
		tmp->val = list[i];
		tmp->next = NULL;
		p-> next= tmp;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
void printLinkList(ListNode *head)
{
	ListNode *p = head;
	while(p){
		cout<<p->val<<"  ";
		p = p->next;
	}
}
