#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

/*
  ˼��: ���������λ��ں�׺���ʽ����ģ�
     ���磺831-5*+;   (8+(3-1)*5=>831-5*+)
  �������:
    ������׺���ʽ�е����ֺͷ���
		�������֣�����
		���ڷ��ţ�
				��ջ�е����Ҳ�����
				��ջ�е����������
				���ݷ��Ž�������
				��������ѹ��ջ��
  ����������ջ�е�Ψһ����Ϊ������
*/

int IsNumber2(char c) {
	return c >= '0' && c <= '9';
}
typedef struct MYNUM {
	LinkNode node;
	int val;
}MyNum;

int Caculate(int left, int right, char c) {
	int ret = 0;
	switch (c) {
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}
	return ret;
}
int main(void) {
	//��׺���ʽ
	char* str = "831-5*+";
	char* p = str;
    //����ջ
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0') {
		//���������ֱ����ջ
		if (IsNumber2(*p)) {
			MyNum* num = (MyNum*)malloc(sizeof(MyNum));
			num->val = *p - '0';
			Push_LinkStack(stack, (LinkNode*)num);
		}
		else {
			//�ȴ�ջ�е����Ҳ�����
			MyNum* right = (MyNum*)Top_LinkStack(stack);
			int rightNum = right->val;
			Pop_LinkStack(stack);
			free(right);
			//ȡ���������
			MyNum* left = (MyNum*)Top_LinkStack(stack);
			int leftNum = left->val;
			Pop_LinkStack(stack);
			free(left);

			int ret = Caculate(leftNum, rightNum, *p);
			//�����ջ
			MyNum* num = (MyNum*)malloc(sizeof(MyNum));
			num->val = ret;
			Push_LinkStack(stack, (LinkNode*)num);
		}
		p++;
	}

	if (Size_LinkStack(stack) == 1) {
		MyNum* num = (MyNum*)Top_LinkStack(stack);
		printf("�������ǣ�%d\n", num->val);
		Pop_LinkStack(stack);
		free(num);
	}
	//�ͷ�ջ
	FreeSpace_LinkStack(stack);

	printf("\n");
	system("pause");
	return 0;
}