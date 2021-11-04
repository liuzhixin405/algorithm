#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "LinkList.h"
#include "../02 ��������/LinkList.h"

//�Զ�����������
typedef struct PERSON {
	char name[64];
	int age;
	int score;
}Person;

//��ӡ����
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
	//����һ������
	LinkList* list = Init_LinkList();
	//��������
	Person p1 = { "��ͭ", 18, 80 };	
	Person p2 = { "����", 19, 85 };
	Person p3 = { "�ƽ�", 20, 90 };
	Person p4 = { "��ʯ", 21, 95 };
	Person p5 = { "��ҫ", 22, 100 };

	//���ݲ�������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	//��ӡ
	Print_LinkList(list, MyPrint);

	//ɾ��3
	RemoveByPos_LinkList(list, 3);

	//��ӡ
	printf("--------------------\n");
	Print_LinkList(list, MyPrint);

	//���ص�һ�����
	printf("--------------------\n");
	Person* ret= (Person*)Front_LinkList(list);
	printf("�׽�����ݣ�Name:%s, Age:%d, Score:%d\n", ret->name, ret->age, ret->score);
	
	/*
	//����(�Ƚϵ�������ָ�����͵�data),����������ֵ
	Person f1 = { "��ͭ2", 18, 80 };
	Person f2 = { "��ͭ", 18, 80 };
	int index = Find_LinkList(list, &f1, MyCompare);
	printf("�鵽������ֵ��%d", index);
	*/
	//��������
	FreeSpace_LinkList(list);

	printf("\n");
	system("pause"); 
	return 0;
}
