#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"

/*   约瑟夫问题-循环链表典型应用
     例题：n个人围成一个圆圈，首先第1个人从1开始一个人一个人顺时针报数，
 报到第m个人，令其出列，然后再从下一个人开始从1顺时针报数，报到第m个人
 再令其出列，.，如此下去，求出列顺序。
     假设：m=8，n=3
*/

#define M 8
#define N 3

typedef struct MYNNUM {
	CircleLinkNode node;
	int val;
}MyNum;

void MyPrint(CircleLinkNode* data) {
	MyNum* num = (MyNum*)data;
	printf("%d ", num->val);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2) {
	MyNum* num1 = (MyNum*)data1;
	MyNum* num2 = (MyNum*)data2;
	if (num1->val == num2->val) {
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
int main(void) {

	//创建循环链表
	CircleLinkList* clist = Init_CircleLinkList();
	//链表插入数据
	MyNum num[M];
	for (int i = 0; i < M; i++) {
		num[i].val = i + 1;
		Insert_CircleLinkList(clist, i, (CircleLinkNode*) &num[i]);
	}

	//打印
	Print_CircleLinkList(clist, MyPrint);
	printf("\n");
	//printf("%d", Size_CircleLinkList(clist));

	int index = 1;
	//辅助指针
	CircleLinkNode* pCurrent = clist->head.next;
	while (Size_CircleLinkList(clist) > 1) {

		if (index == N) {
			MyNum* temNum = (MyNum*)pCurrent;
			printf("%d ", temNum->val);

			//缓存待删除结点的下一个结点
			CircleLinkNode* pNext = pCurrent->next;
			//根据值删除
			RemoveByValue_CircleLinkList(clist, pCurrent, MyCompare);
			pCurrent = pNext;
			//跳过头节点
			if (pCurrent == &(clist->head)) {
				pCurrent = pCurrent->next;
			}
			index = 1;
		}

		//printf("%d\n", Size_CircleLinkList(clist));

		pCurrent = pCurrent->next;
		if (pCurrent == &(clist->head)) {
			pCurrent = pCurrent->next;
		}
		index++;
	}

	if (Size_CircleLinkList(clist) == 1) {
		MyNum* tempNum = (MyNum*)Front_CircleLinkList(clist);
		printf("%d ", tempNum->val);
	}
	else {
		printf("出错！");
	}

	//释放链表内存
	FreeSpace_CircleLinkList(clist);

	printf("\n");
	system("pause");
	return 0;
}