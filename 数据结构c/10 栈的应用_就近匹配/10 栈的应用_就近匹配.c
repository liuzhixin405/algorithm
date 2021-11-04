#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

/*
   几乎所有的编译器都具有检测括号是否匹配的能力，那么如何实现编译器中的符号成对检测？
  如下字符串：
   #include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;}
   解决思路：扫描字符串，如果碰到左括号直接入栈，如果碰到右括号，从栈顶弹出里面的括号，
 判断其是否是左括号，如果是匹面成功
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

	//创建栈容器
	LinkStack* stack = Init_LinkStack();

	char* p = str;
	int index = 0;
	while (*p != '\0') {
		//如果左括号直接进栈
		if (IsLeft(*p)) {
			Push_LinkStack(stack, (LinkNode*)CreateMyChar(p, index));
		}

		//如果是右括号从栈顶弹出元素判断是不是左括号
		if (IsRight(*p)){
			if (Size_LinkStack(stack) > 0) {
				MyChar* mychar = (MyChar*)Top_LinkStack(stack);
				if (IsLeft(*(mychar->pAddres))) {
					Pop_LinkStack(stack);
					free(mychar);
				}
			}
			else {
				printf("右括号没有匹配的左括号：\n");
				ShowError(str, index);
				break;
			}
		}

		p++;
		index++;
	}

	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("左括号没有匹配的右括号：\n");
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		free(mychar);
	}

	printf("\n");
	system("pause");
	return 0;
}