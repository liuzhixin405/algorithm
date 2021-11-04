#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

/*
  后缀表达式（由波兰科学家在20世纪50年代提出）
  将运算符放在数字后面===》符合计算机运算
  我们习惯的数学表达式叫做中缀表达式===》符合人类思考习惯
  实例:
   5+4=>54+
   1+2*3=>123*+
   8+(3-1)*5=>831-5*+

   中缀转后缀算法：遍历中缀表达式中的数字和符号：
	对于数字：直接输出
	对于符号：
	  左括号：进栈
	  运算符号：与栈顶符号进行优先级比较
        >若栈顶符号优先级低：此符号进栈
		  （默认栈顶若是左括号，左括号优先级最低）
	    >若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
	  右括号：将栈顶符号弹出并输出，直到匹配左括号
	遍历结束：将栈中的所有符号弹出并输出
*/


//判断是否是数字
int IsNumber(char c) {
	return c >= '0' && c <= '9';
}
//数字操作
void NumberOperate(char* p) {
	printf("%c", *p);
}

//判断是不是左括号
int IsLeft(char c) {
	return c == '(';
}

typedef struct MYCHAR {
	LinkNode node;
	char* p;
}MyChar;

//创建MyChar
MyChar* CreateMyChar(char* p) {
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

//左括号操作
void LeftOperate(LinkStack* stack, char* p) {
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}
//判断是不是右括号
int IsRight(char c) {
	return c == ')';
}
//右括号操作
void RightOperate(LinkStack* stack) {
	//先判断栈中有无元素
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		//如果匹配到左括号
		if (IsLeft(*(mychar->p))) {
			Pop_LinkStack(stack);
			break;
		}
		//先输出再弹出
		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		//释放内存
		free(mychar);
	}
}
//判断是不是运算符号
int IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
//返回运算符号优先级
int GetPriority(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}
//运算符号的操作
void OperatorOperate(LinkStack* stack,char* p) {
	//先取出栈顶符号
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	
	if (mychar == NULL) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	//如果栈项优先级低于当前字符的优先级直接入栈
	if (GetPriority(*(mychar->p)) < GetPriority(*p)) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	//如果栈顶符号优先级不低
	else {
		while (Size_LinkStack(stack) > 0) {
			MyChar* mychar2= (MyChar*)Top_LinkStack(stack);
			//如果优先级低当前符号入栈
			if (GetPriority(*(mychar2->p)) < GetPriority(*p)) {
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				break;
			}
			//先输出,再弹出
			printf("%c", *(mychar2->p));
			Pop_LinkStack(stack);
			//释放内存
			free(mychar2);
		}
	}
}

int main01(void) {

	char* str = "8+(3-1)*5";
	char* p = str;

	//创建栈
	LinkStack* stack = Init_LinkStack();

	while (*p != '\0') {
		//如果是数字
		if (IsNumber(*p)) {
			NumberOperate(p);
		}
		//如果是左括号，直接进栈
		if (IsLeft(*p)) {
			LeftOperate(stack, p);
		}
		//如果是右括号
		if (IsRight(*p)) {
			RightOperate(stack);
		}
		//如果是运算符号
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