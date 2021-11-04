#include <iostream>
#include<malloc.h>
typedef struct Node {
	int data;
	struct Node* pNext;
}NODE, * PNODE;


typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK pS);
void push(PSTACK pS, int);
void traverse(PSTACK pS);
bool pop(PSTACK, int*);
void clear(PSTACK pS);

int main()
{
	STACK S;
	int val;
	init(&S);
	push(&S, 1);
	push(&S, 2);
	traverse(&S);
	if (pop(&S, &val)) {
		printf("出栈成功, 出栈值为 %d \n", val);
	}
	else {
		printf("出栈失败\n");
	}
	/*if (pop(&S, &val)) {
		printf("出栈成功, 出栈值为 %d \n", val);
	}
	else {
		printf("出栈失败\n");
	}
	if (pop(&S, &val)) {
		printf("出栈成功, 出栈值为 %d \n", val);
	}
	else {
		printf("出栈失败\n");
	}*/
	clear(&S);
	traverse(&S);
	return 0;
}

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop) {
		printf("动态分配内存失败!\n");
		exit(-1);
	}
	else {
		pS->pBottom = pS->pTop;
	}
}
/// <summary>
/// 压栈
/// </summary>
/// <param name="pS"></param>
/// <param name="val"></param>
void push(PSTACK pS, int val) {
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	return;
}
/// <summary>
/// 遍历
/// </summary>
/// <param name="pS"></param>
void traverse(PSTACK pS) {
	PNODE p = pS->pTop;
	while (p != pS->pBottom) {
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

/// <summary>
/// 空判断
/// </summary>
/// <param name="pS"></param>
/// <returns></returns>
bool empty(PSTACK pS) {
	if (pS->pBottom == pS->pTop)
		return true;
	else
		return false;
}
/// <summary>
/// 出栈
/// </summary>
/// <param name="pS"></param>
/// <param name="pVal"></param>
/// <returns></returns>
bool pop(PSTACK pS, int* pVal) {
	if (empty(pS)) {
		return false;
	}
	else {
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		return true;
	}

}
/// <summary>
/// 清空
/// </summary>
/// <param name="pS"></param>
void clear(PSTACK pS) {
	if (empty(pS)) {
		return;
	}
	else {
		PNODE p = pS->pTop;
		PNODE q = NULL;
		while (p != pS->pBottom) {
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}