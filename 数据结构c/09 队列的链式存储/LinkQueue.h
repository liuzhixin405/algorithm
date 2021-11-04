#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ʽ���еĽ��
typedef struct LINKNODE {
	void* data;     //�ڵ�����
	struct LINKNODE* next;
}LinkNode;

//��ʽ����
typedef struct LINKQUEUE {
	LinkNode* head;
	LinkNode* tail;
	int size;
}LinkQueue;

//��ʼ�� 
LinkQueue* Init_LinkQueue();
//����
void Push_LinkQueue(LinkQueue* queue, void* data);
//���ض�ͷԪ��
void* Front_LinkQueue(LinkQueue* queue);
//����
void Pop_LinkQueue(LinkQueue* queue);
//���ض�βԪ��
void* Back_LinkQueue(LinkQueue* queue);
//���ش�С
int Size_LinkQueue(LinkQueue* queue);
//��ն���
void Clear_LinkQueue(LinkQueue* queue);
//����
void FreeSpace_LinkQueue(LinkQueue* queue);

#endif // !LINKQUEUE_H

