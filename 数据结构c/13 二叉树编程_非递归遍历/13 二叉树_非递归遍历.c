#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LinkStack.h"

#define MY_FALSE 0
#define MY_TRUE  1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*           A
	   B          F
		  C           G
		D   E       H
����������ȷ��ʸ��ڷ������ٷ�����
ABCDEFGH
��������������ٸ�����
BDCEAFHG
������������������ٸ�
DECBHGFA
   ���ǿ��Եݹ�ļ�����������ĸ߶Ⱥ��������ĸ߶ȣ�
   Ȼ��ȡ���ߵ����ֵ��1��Ϊ��ö������ĸ߶ȡ�
*/

//���������
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;

}BinaryNode;

//�������ķǵݹ�����Ľ��
typedef struct BITREESTACKNODE {
	LinkNode node;
	BinaryNode* root;
	int flag;
}BiTreeStackNode;

//����ջ�еĽ��
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node, int flag) {
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;
	return newnode;
}
//�ǵݹ����
void NonRecursion(BinaryNode* root) {
	//����ջ
	LinkStack* stack = Init_LinkStack();
	//�Ѹ��ڵ��ӵ�ջ��
	Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));

	while (Size_LinkStack(stack) > 0) {
		//�ȵ���ջ��Ԫ��
		BiTreeStackNode* node = (BiTreeStackNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);

		//�жϵ����Ľڵ��Ƿ�Ϊ��
		if (node->root == NULL) {
			continue;
		}
		if (node->flag == MY_TRUE) {
			printf("%c", node->root->ch);
		}
		else {
			/*
		//1.�������
			//��ǰ����ҽ����ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//��ǰ���������ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
			//��ǰ�����ջ
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
			*/

			/*
		//2.�������
			//��ǰ����ҽ����ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//��ǰ�����ջ
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
			//��ǰ���������ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
		    */

			
		//3.�������
			//��ǰ�����ջ
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
			//��ǰ����ҽ����ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//��ǰ���������ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
			
		}

	}
}

//�������ĵݹ����
void Recursion(BinaryNode* root) {
	if (root == NULL) {
		return;
	}
	/*
//1.�������
	//��ӡ���ڵ�
	printf("%c", root->ch);
	//��ӡ������
	Recursion(root->lchild);
	//��ӡ������
	Recursion(root->rchild);
	*/
	/*
//2.�������
	//��ӡ������
	Recursion(root->lchild);
	//��ӡ���ڵ�
	printf("%c", root->ch);
	//��ӡ������
	Recursion(root->rchild);
	*/
	
//3.�������
	//��ӡ������
	Recursion(root->lchild);
	//��ӡ������
	Recursion(root->rchild);
	//��ӡ���ڵ�
	printf("%c", root->ch);
	
}

void CreateBinaryTree() {
	//�����ڵ�
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };

	//�����ڵ��ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	//�������ķǵݹ������ӡ
	NonRecursion(&node1);
	printf("\n");

	Recursion(&node1);
}


int main(void) {

	CreateBinaryTree();
	printf("\n");
	system("pause");
	return 0;
}