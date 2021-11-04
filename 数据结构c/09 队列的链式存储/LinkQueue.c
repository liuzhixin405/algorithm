#include"LinkQueue.h"

//��ʼ�� 
LinkQueue* Init_LinkQueue() {
	LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	queue->size = 0;

	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}
//����
void Push_LinkQueue(LinkQueue* queue, void* data) {
	if (queue == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	//�����µĽ��
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	if (queue->head == NULL)
	{
		queue->head = queue->tail = newnode;
	}
	else {
		queue->tail->next = newnode;
		queue->tail = queue->tail->next;
	}
	queue->size++;
}

//���ض�ͷԪ��
void* Front_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->head->data;
}

//����
void Pop_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return;
	}
	if (queue->size == 0) {
		return;
	}
	LinkNode* pDel = queue->head;
	LinkNode* pNext = queue->head;
	queue->head = pNext->next;
	queue->size--;
	free(pDel);
}

//���ض�βԪ��
void* Back_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	LinkNode* p = queue->head;
	while (p->next != NULL) {
		p = p->next;
	}
	return p->data;
}

//���ش�С
int Size_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return -1;
	}
	return queue->size;
}
//��ն���
void Clear_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return;
	}
	queue->size = 0;
}
//����
void FreeSpace_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return;
	}
	free(queue);
}