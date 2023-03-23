#include<vector>
#include <stack>
#include<string> 
#include<iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stdlib.h>
#include <numeric> 
#include <sstream>
using namespace std;

//链表结构体
typedef struct ListNode {
	int val;
	ListNode *next;
}ListNode;

//树的结构体
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
}TreeNode;

//链表创建，没有头节点，使用数组创建
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

//链表输出
void printLinkList(ListNode *head)
{
	ListNode *p = head;
	while(p){
		cout<<p->val<<"  ";
		p = p->next;
	}
}


