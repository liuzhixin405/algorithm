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
	//��������
	LinkQueue* queue = Init_LinkQueue();
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

	//���
	Push_LinkQueue(queue, (LinkNode*)& p1);
	Push_LinkQueue(queue, (LinkNode*)& p2);
	Push_LinkQueue(queue, (LinkNode*)& p3);
	Push_LinkQueue(queue, (LinkNode*)& p4);
	Push_LinkQueue(queue, (LinkNode*)& p5);

	//�����ͷԪ��
	Person* fnode = (Person*)Front_LinkQueue(queue);
	printf("��ͷԪ�أ�Name:%s, Age:%d\n", fnode->name, fnode->age);


	//�����βԪ��
	Person* backPerson = (Person*)Back_LinkQueue(queue);
	printf("��βԪ�أ�Name:%s, Age:%d\n", backPerson->name, backPerson->age);

	//���
	while (Size_LinkQueue(queue) > 0) {
		//ȡ����ͷԪ��
		Person* p = (Person*)Front_LinkQueue(queue);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//����ջ��Ԫ��
		Pop_LinkQueue(queue);
	}
	//���ٶ���
	FreeSpace_LinkQueue(queue);
	printf("\n");
	system("pause");
	return 0;
}