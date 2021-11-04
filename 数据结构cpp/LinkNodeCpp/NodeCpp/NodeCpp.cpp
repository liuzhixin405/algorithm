#include <iostream>
#include<stdlib.h>
#include<malloc.h>
typedef struct Node {
	int data;
	struct Node* pNext;
} *PNODE, NODE;
PNODE create_list();
void traverse_list(PNODE);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
void sort_list(PNODE pHead);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);

int main()
{
	PNODE pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);
	int len = length_list(pHead);
	printf("链表长度为%d\n", len);
	insert_list(pHead, 3, 10);
	printf("排序后: \n");
	sort_list(pHead);
	traverse_list(pHead);

	printf("准备删除节点\n");
	int val;
	if(delete_list(pHead, 4, &val)) {
		printf("删除成功,删除的元素是： %d\n", val);
	}
	else {
		printf("删除失败!\n");
	}

	return 0;
}

/// <summary>
/// 创建
/// </summary>
/// <returns></returns>
PNODE create_list() {
	int len;
	int i;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead) {
		printf("分配内存失败,程序终止\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入链表的节点个数： len= ");
	scanf_s("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值: ", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			printf("分配内存失败,程序终止\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
/// <summary>
/// 遍历
/// </summary>
/// <param name="pHead"></param>
void traverse_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

/// <summary>
/// 空判断
/// </summary>
/// <param name="pHead"></param>
/// <returns></returns>
bool is_empty(PNODE pHead) {
	if (NULL == pHead->pNext) {
		printf("链表为空\n");
		return true;
	}
	else {
		return false;
	}
}
/// <summary>
/// 长度
/// </summary>
/// <param name="pHead"></param>
/// <returns></returns>
int length_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	int len = 0;
	while (NULL != p) {
		++len;
		p = p->pNext;
	}
	return len;
}
/// <summary>
/// 排序
/// </summary>
/// <param name="pHead"></param>
void sort_list(PNODE pHead) {
	int i, j, t;
	PNODE p, q;
	int len = length_list(pHead);
	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext) {
		for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext) {
			if (p->data > q->data) {
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}
/// <summary>
/// pos从1开始    从pos个节点的位置插入一个新的节点
/// </summary>
/// <param name="pHead"></param>
/// <param name="pos"></param>
/// <param name="val"></param>
/// <returns></returns>
bool insert_list(PNODE pHead, int pos, int val) {
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i < pos - 1) {
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p)
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew) {
		printf("内存分配失败");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;
}

/// <summary>
/// 删除
/// </summary>
/// <param name="pHead"></param>
/// <param name="pos"></param>
/// <param name="pVal"></param>
/// <returns></returns>
bool delete_list(PNODE pHead, int pos, int* pVal) {
	int i = 0;
	PNODE p = pHead;
	while (NULL != p->pNext && i < pos - 1) {
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext)
		return false;
	PNODE q = p->pNext;
	*pVal = q->data;
	//删除p后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}