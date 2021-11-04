#include"LinkQueue.h"

//初始化 
LinkQueue* Init_LinkQueue() {
	LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	queue->size = 0;

	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}
//入列
void Push_LinkQueue(LinkQueue* queue, void* data) {
	if (queue == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	//创建新的结点
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

//返回队头元素
void* Front_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->head->data;
}

//出队
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

//返回队尾元素
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

//返回大小
int Size_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return -1;
	}
	return queue->size;
}
//清空队列
void Clear_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return;
	}
	queue->size = 0;
}
//销毁
void FreeSpace_LinkQueue(LinkQueue* queue) {
	if (queue == NULL) {
		return;
	}
	free(queue);
}