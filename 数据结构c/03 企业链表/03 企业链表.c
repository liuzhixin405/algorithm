#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../03 ��ҵ����/LinkList.h"

//����ڵ�
typedef struct PERSON {
	LinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(LinkNode* data) {
	Person* p = (Person*)data;
	printf("Name:%s, Age:%d\n", p->name, p->age);
}

int MyCompare(LinkNode* node1, LinkNode* node2) {
	Person* p1 = (Person*)node1;
	Person* p2 = (Person*)node2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age) {
		return 0;
	}
	return -1;
}


int main(void)
{
	//��������
	LinkList* list = Init_LinkList();

	//��������
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "��ɮ");
	strcpy(p2.name, "���");
	strcpy(p3.name, "�˽�");
	strcpy(p4.name, "ɳɮ");
	strcpy(p5.name, "������");

	p1.age = 100;
	p2.age = 200;
	p3.age = 300;
	p4.age = 400;
	p5.age = 500;

	//������������
	Insert_LinkList(list, 0, (LinkNode*) &p1);
	Insert_LinkList(list, 0, (LinkNode*) &p2);
	Insert_LinkList(list, 0, (LinkNode*) &p3);
	Insert_LinkList(list, 0, (LinkNode*) &p4);
	Insert_LinkList(list, 0, (LinkNode*) &p5);

	//��ӡ
	Print_LinkList(list, MyPrint);

	

	//ɾ���ڵ�
	Remove_LinkList(list, 2);

	//��ӡ
	printf("--------------------\n");
	Print_LinkList(list, MyPrint);

    //����
	Person findP;
	strcpy(findP.name, "��ɮ");
	findP.age = 100;
	int pos = Find_LinkList(list, (LinkNode*) &findP, MyCompare);
	printf("λ�ã�%d\n", pos);

	//�ͷ������ڴ�
	FreeSpace_LinkList(list);

	printf("\n");
	system("pause");
	return 0;
}