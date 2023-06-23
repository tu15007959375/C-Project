#include<vector>
#include <stack>
#include<string> 
#include<iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stdlib.h>
#include <numeric> 
#include <queue>
#include <sstream>
#include <set>
#include <map>
#include <bitset>
#include <string.h>
#include <unordered_set>
#include <ctype.h>
using namespace std;

//链表结构体
typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
}ListNode;

//树的结构体
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

void Create_TreeNode(TreeNode *&t,int x){  //在指针t处生成一个新的节点，内容为x
	t=new TreeNode(x);
}
void createTree(TreeNode *&root,vector<int> val,int i)
{
	Create_TreeNode(root,val[i]);
	if((long long unsigned)(i*2)<val.size()&&val[2*i]!=-1)
		createTree(root->left,val,i*2);
	if((long long unsigned)(i*2+1)<val.size()&&val[2*i+1]!=-1)
		createTree(root->right,val,i*2+1);
}
void printTree(TreeNode *root)
{
	if(!root)
		return;
	cout<<root->val<<"\t";
	printTree(root->left);
	printTree((root->right));
}

