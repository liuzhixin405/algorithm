#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct PERSON {
	LinkNode node;
	char name[64];
	int age;
}Person;

int main(void) {
	//����ջ
	LinkStack* stack = Init_LinkStack();
	//��������
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

	//��ջ
	Push_LinkStack(stack, (LinkNode*)& p1);
	Push_LinkStack(stack, (LinkNode*)& p2);
	Push_LinkStack(stack, (LinkNode*)& p3);
	Push_LinkStack(stack, (LinkNode*)& p4);
	Push_LinkStack(stack, (LinkNode*)& p5);

	//���
	while (Size_LinkStack(stack) > 0) {
		//ȡ��ջ��Ԫ��
		Person* p = (Person*)Top_LinkStack(stack);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//����ջ��Ԫ��
		Pop_LinkStack(stack);
	}
	//����ջ
	FreeSpace_LinkStack(stack);

	printf("\n");
	system("pause");
	return 0;
}