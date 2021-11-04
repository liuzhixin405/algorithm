#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LinkQueue.h"

typedef struct PERSON {
	char name[64];
	int age;
}Person;

int main(void) {
	//创建队列
	LinkQueue* queue = Init_LinkQueue();
	//创建数据
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;

	//入队
	Push_LinkQueue(queue, (LinkNode*)& p1);
	Push_LinkQueue(queue, (LinkNode*)& p2);
	Push_LinkQueue(queue, (LinkNode*)& p3);
	Push_LinkQueue(queue, (LinkNode*)& p4);
	Push_LinkQueue(queue, (LinkNode*)& p5);

	//输出队头元素
	Person* fnode = (Person*)Front_LinkQueue(queue);
	printf("队头元素：Name:%s, Age:%d\n", fnode->name, fnode->age);


	//输出队尾元素
	Person* backPerson = (Person*)Back_LinkQueue(queue);
	printf("队尾元素：Name:%s, Age:%d\n", backPerson->name, backPerson->age);

	//输出
	while (Size_LinkQueue(queue) > 0) {
		//取出队头元素
		Person* p = (Person*)Front_LinkQueue(queue);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//弹出栈顶元素
		Pop_LinkQueue(queue);
	}
	//销毁队列
	FreeSpace_LinkQueue(queue);
	printf("\n");
	system("pause");
	return 0;
}