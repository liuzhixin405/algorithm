#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//链式队列的结点
typedef struct LINKNODE {
	void* data;     //节点数据
	struct LINKNODE* next;
}LinkNode;

//链式队列
typedef struct LINKQUEUE {
	LinkNode* head;
	LinkNode* tail;
	int size;
}LinkQueue;

//初始化 
LinkQueue* Init_LinkQueue();
//入列
void Push_LinkQueue(LinkQueue* queue, void* data);
//返回队头元素
void* Front_LinkQueue(LinkQueue* queue);
//出队
void Pop_LinkQueue(LinkQueue* queue);
//返回队尾元素
void* Back_LinkQueue(LinkQueue* queue);
//返回大小
int Size_LinkQueue(LinkQueue* queue);
//清空队列
void Clear_LinkQueue(LinkQueue* queue);
//销毁
void FreeSpace_LinkQueue(LinkQueue* queue);

#endif // !LINKQUEUE_H

