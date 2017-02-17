// ɾ���������ظ��ڵ�.cpp : �������̨Ӧ�ó������ڵ㡣
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

	ListNode *pCur = pHead;			//ָ��ǰ�ڵ�
	ListNode *pNext = pCur->next;	//ָ����һ���ڵ�

	while (pNext != NULL){
		while ((pNext->next != NULL) && (pCur->val == pNext->val)){
			pNext = pNext->next;
		}
		if (pCur->next!=pNext){ //���ظ�
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

