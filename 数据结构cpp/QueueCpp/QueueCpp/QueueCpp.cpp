#include <iostream>
#include<malloc.h>

typedef struct Queue {
	int* pBase;
	int front;
	int rear;
} QUEUE;

void init(QUEUE*);
bool full_queu(QUEUE* pQ);
bool en_queue(QUEUE* pQ, int val);
void traverse_queue(QUEUE* pQ);
bool out_queue(QUEUE* pQ, int* pVal);

int main()
{
	QUEUE Q;
	int val;
	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	en_queue(&Q, 8);
	traverse_queue(&Q);
	if (out_queue(&Q, &val)) {
		printf("出队成功,出队元素是: %d\n", val);
	}
	else {
		printf("出队失败\n");
	}
	return 0;
}
/// <summary>
/// 初始化
/// </summary>
/// <param name="pQ"></param>
void init(QUEUE* pQ) {
	pQ->pBase = (int*)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}
/// <summary>
/// 满
/// </summary>
/// <param name="pQ"></param>
/// <returns></returns>

bool full_queu(QUEUE* pQ) {
	if ((pQ->rear + 1) % 6 == pQ->front) {
		return true;
	}
	else {
		return false;
	}
}

/// <summary>
/// 入队
/// </summary>
/// <param name="pQ"></param>
/// <param name="val"></param>
/// <returns></returns>
bool en_queue(QUEUE* pQ, int val) {
	if (full_queu(pQ)) {
		return false;
	}
	else {
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
}
/// <summary>
/// 遍历
/// </summary>
/// <param name="pQ"></param>
void traverse_queue(QUEUE* pQ) {
	int i = pQ->front;
	while (i != pQ->rear) {
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
}
/// <summary>
/// 空
/// </summary>
/// <param name="pQ"></param>
/// <returns></returns>
bool empty_queue(QUEUE* pQ) {
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
/// <summary>
/// 出队
/// </summary>
/// <param name="pQ"></param>
/// <param name="pVal"></param>
/// <returns></returns>
bool out_queue(QUEUE* pQ, int* pVal) {
	if (empty_queue(pQ)) {
		return false;
	}
	else {
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
	}
}