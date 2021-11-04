#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

/*
  ��׺���ʽ���ɲ�����ѧ����20����50��������
  ��������������ֺ���===�����ϼ��������
  ����ϰ�ߵ���ѧ���ʽ������׺���ʽ===����������˼��ϰ��
  ʵ��:
   5+4=>54+
   1+2*3=>123*+
   8+(3-1)*5=>831-5*+

   ��׺ת��׺�㷨��������׺���ʽ�е����ֺͷ��ţ�
	�������֣�ֱ�����
	���ڷ��ţ�
	  �����ţ���ջ
	  ������ţ���ջ�����Ž������ȼ��Ƚ�
        >��ջ���������ȼ��ͣ��˷��Ž�ջ
		  ��Ĭ��ջ�����������ţ����������ȼ���ͣ�
	    >��ջ���������ȼ����ͣ���ջ�����ŵ����������֮���ջ
	  �����ţ���ջ�����ŵ����������ֱ��ƥ��������
	������������ջ�е����з��ŵ��������
*/


//�ж��Ƿ�������
int IsNumber(char c) {
	return c >= '0' && c <= '9';
}
//���ֲ���
void NumberOperate(char* p) {
	printf("%c", *p);
}

//�ж��ǲ���������
int IsLeft(char c) {
	return c == '(';
}

typedef struct MYCHAR {
	LinkNode node;
	char* p;
}MyChar;

//����MyChar
MyChar* CreateMyChar(char* p) {
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

//�����Ų���
void LeftOperate(LinkStack* stack, char* p) {
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}
//�ж��ǲ���������
int IsRight(char c) {
	return c == ')';
}
//�����Ų���
void RightOperate(LinkStack* stack) {
	//���ж�ջ������Ԫ��
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		//���ƥ�䵽������
		if (IsLeft(*(mychar->p))) {
			Pop_LinkStack(stack);
			break;
		}
		//������ٵ���
		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		//�ͷ��ڴ�
		free(mychar);
	}
}
//�ж��ǲ����������
int IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
//��������������ȼ�
int GetPriority(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}
//������ŵĲ���
void OperatorOperate(LinkStack* stack,char* p) {
	//��ȡ��ջ������
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	
	if (mychar == NULL) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	//���ջ�����ȼ����ڵ�ǰ�ַ������ȼ�ֱ����ջ
	if (GetPriority(*(mychar->p)) < GetPriority(*p)) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	//���ջ���������ȼ�����
	else {
		while (Size_LinkStack(stack) > 0) {
			MyChar* mychar2= (MyChar*)Top_LinkStack(stack);
			//������ȼ��͵�ǰ������ջ
			if (GetPriority(*(mychar2->p)) < GetPriority(*p)) {
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				break;
			}
			//�����,�ٵ���
			printf("%c", *(mychar2->p));
			Pop_LinkStack(stack);
			//�ͷ��ڴ�
			free(mychar2);
		}
	}
}

int main01(void) {

	char* str = "8+(3-1)*5";
	char* p = str;

	//����ջ
	LinkStack* stack = Init_LinkStack();

	while (*p != '\0') {
		//���������
		if (IsNumber(*p)) {
			NumberOperate(p);
		}
		//����������ţ�ֱ�ӽ�ջ
		if (IsLeft(*p)) {
			LeftOperate(stack, p);
		}
		//�����������
		if (IsRight(*p)) {
			RightOperate(stack);
		}
		//������������
		if (IsOperator(*p)) {
			OperatorOperate(stack, p);
		}
		p++;
	}

	while (Size_LinkStack(stack) > 0) {
		 MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		 printf("%c", *(mychar->p));
		 Pop_LinkStack(stack);
		 free(mychar);
	}
	printf("\n");
	system("pause");
	return 0;
}