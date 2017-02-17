// 删除链表中重复节点.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return NULL;

	ListNode *pPre = new ListNode(0);
	pPre->next = pHead;
	ListNode *pNewHead = pPre;

	ListNode *pCur = pHead;			//指向当前节点
	ListNode *pNext = pCur->next;	//指向下一个节点

	while (pNext != NULL){
		while ((pNext->next != NULL) && (pCur->val == pNext->val)){
			pNext = pNext->next;
		}
		if (pCur->next!=pNext){ //有重复
			pPre->next = pNext;
			pCur = pNext;
			pNext = pCur->next;
		}
		else{
			pPre = pCur;
			pCur = pNext;
			pNext = pCur->next;
		 }
	}
	return pNewHead->next;
}


int _tmain(int argc, _TCHAR* argv[])
{
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(2);
	ListNode ln4(3);
	ListNode ln5(5);
	ListNode ln6(5);
	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;
	ln5.next = &ln6;

	ListNode *p = deleteDuplication(&ln1);
	while (p != NULL){
		cout << p->val;
		p = p->next;
	}
	return 0;
}

