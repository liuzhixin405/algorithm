#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

/*
   �������еı����������м�������Ƿ�ƥ�����������ô���ʵ�ֱ������еķ��ųɶԼ�⣿
  �����ַ�����
   #include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;}
   ���˼·��ɨ���ַ������������������ֱ����ջ��������������ţ���ջ��������������ţ�
 �ж����Ƿ��������ţ������ƥ��ɹ�
 */

typedef struct MYCHAR {
	LinkNode node;
	char* pAddres;
	int index;
}MyChar;

int IsLeft(char c) {
	return c == '(';
}

int IsRight(char c) {
	return c == ')';
}

MyChar* CreateMyChar(char* p, int index) {
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->pAddres = p;
	mychar->index = index;
	return mychar;
}

void ShowError(char* str, int pos) {
	printf("%s\n", str);
	for (int i = 0; i < pos; i++) {
		printf(" ");
	}
		printf("A");
}

int main(void) {

	//char* str = "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;}";
	char* str = "1+2+6(dsf)df)sflp(fdsa)";

	//����ջ����
	LinkStack* stack = Init_LinkStack();

	char* p = str;
	int index = 0;
	while (*p != '\0') {
		//���������ֱ�ӽ�ջ
		if (IsLeft(*p)) {
			Push_LinkStack(stack, (LinkNode*)CreateMyChar(p, index));
		}

		//����������Ŵ�ջ������Ԫ���ж��ǲ���������
		if (IsRight(*p)){
			if (Size_LinkStack(stack) > 0) {
				MyChar* mychar = (MyChar*)Top_LinkStack(stack);
				if (IsLeft(*(mychar->pAddres))) {
					Pop_LinkStack(stack);
					free(mychar);
				}
			}
			else {
				printf("������û��ƥ��������ţ�\n");
				ShowError(str, index);
				break;
			}
		}

		p++;
		index++;
	}

	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("������û��ƥ��������ţ�\n");
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		free(mychar);
	}

	printf("\n");
	system("pause");
	return 0;
}