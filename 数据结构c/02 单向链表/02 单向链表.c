#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "LinkList.h"
#include "../02 单向链表/LinkList.h"

//自定义数据类型
typedef struct PERSON {
	char name[64];
	int age;
	int score;
}Person;

//打印函数
void MyPrint(void* data) {
	Person* p = (Person*)data;
	printf("Name:%s, Age:%d, Score:%d\n", p->name, p->age, p->score);
}

/*
int MyCompare(Person* f1, Person* f2) {
	//Person* f1 = (Person*)f1;
	if (strcmp(f1->name, f2->name) == 0 && f1->age == f2->age  && f1->score == f2->score) {
		return 0;
	}
	return -1;
}
*/
int main(void) 
{
	//创建一个链表
	LinkList* list = Init_LinkList();
	//创建数据
	Person p1 = { "青铜", 18, 80 };	
	Person p2 = { "白银", 19, 85 };
	Person p3 = { "黄金", 20, 90 };
	Person p4 = { "钻石", 21, 95 };
	Person p5 = { "星耀", 22, 100 };

	//数据插入链表
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	//打印
	Print_LinkList(list, MyPrint);

	//删除3
	RemoveByPos_LinkList(list, 3);

	//打印
	printf("--------------------\n");
	Print_LinkList(list, MyPrint);

	//返回第一个结点
	printf("--------------------\n");
	Person* ret= (Person*)Front_LinkList(list);
	printf("首结点数据：Name:%s, Age:%d, Score:%d\n", ret->name, ret->age, ret->score);
	
	/*
	//查找(比较的是已有指针类型的data),返回其索引值
	Person f1 = { "青铜2", 18, 80 };
	Person f2 = { "青铜", 18, 80 };
	int index = Find_LinkList(list, &f1, MyCompare);
	printf("查到的索引值：%d", index);
	*/
	//销毁链表
	FreeSpace_LinkList(list);

	printf("\n");
	system("pause"); 
	return 0;
}
