#pragma once
#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#define MAX_SIZE 1024

#include <stdio.h>
#include <stdlib.h>

typedef struct SEQQUEUE_H {
	void* data[MAX_SIZE];
	int size;
}SeqQueue;

//初始化 //入列//返回队头元素//出队//返回队尾元素//返回大小//清空队列//销毁
SeqQueue* Init_SeqQueue();
//入列
void Push_SeqQueue(SeqQueue* queue, void* data);
//返回队头元素
void* Front_SeqQueue(SeqQueue* queue);
//出队
void Pop_SeqQueue(SeqQueue* queue);
//返回队尾元素
void* Back_SeqQueue(SeqQueue* queue);
//返回大小
int Size_SeqQueue(SeqQueue* queue);
//清空队列
void Clear_SeqQueue(SeqQueue* queue);
//销毁
void FreeSpace_SeqQueue(SeqQueue* queue);

#endif // !SEQQUEUE_H

