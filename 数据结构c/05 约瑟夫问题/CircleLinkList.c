#include <stdio.h>
#include <stdlib.h>
#include "CircleLinkList.h"

//��ʼ������ 
CircleLinkList* Init_CircleLinkList()
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}
//���뺯��
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data)
{
	if (clist == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}

	if (pos<0 || pos>clist->size) {
		pos = clist->size;
	}

	//����λ�ò��ҽ��λ��
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//������������
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
}
// ��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist)
{
	return clist->head.next;
}
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL) {
		return;
	}
	if (pos<0 || pos>= clist->size) {
		return;
	}

	//����pos�ҽ��
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//���浱ǰ�ڵ����һ���ڵ�
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;

	clist->size--;
}
//����ֵȥɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
	if (clist == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}

	//�����ѭ������
	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = pPrev->next;
	int i = 0;
	for (i = 0; i < clist->size; i++) {
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE) {
			pPrev->next = pCurrent->next;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
	clist->size--;
}
//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist)
{
	if (clist->size == 0) {
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
//����
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
	if (clist == NULL) {
		return -1;
	}
	if (data == NULL) {
		return -1;
	}

	CircleLinkNode* pCurrent = clist->head.next;
	int flag = -1;
	for (int i = 0; i < clist->size; i++) {
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE) {
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}

	return flag;
}
//��ӡ�ڵ�
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print)
{
	if (clist == NULL) {
		return;
	}
	//����ָ�����
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size * 1; i++) {
		if (pCurrent == &(clist->head)) {
			pCurrent = pCurrent->next;
			printf("-----------------------\n");
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist)
{
	if (clist == NULL) {
		return;
	}

	free(clist);
}
