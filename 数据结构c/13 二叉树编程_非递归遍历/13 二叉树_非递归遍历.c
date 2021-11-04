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
先序遍历：先访问根在访问左再访问右
ABCDEFGH
中序遍历：先左再根再右
BDCEAFHG
后序遍历：先左再右再根
DECBHGFA
   我们可以递归的计算出左子树的高度和右子树的高度，
   然后取二者的最大值加1最为这棵二叉树的高度。
*/

//二叉树结点
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;

}BinaryNode;

//二叉树的非递归遍历的结点
typedef struct BITREESTACKNODE {
	LinkNode node;
	BinaryNode* root;
	int flag;
}BiTreeStackNode;

//创建栈中的结点
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node, int flag) {
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;
	return newnode;
}
//非递归遍历
void NonRecursion(BinaryNode* root) {
	//创建栈
	LinkStack* stack = Init_LinkStack();
	//把根节点扔到栈里
	Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));

	while (Size_LinkStack(stack) > 0) {
		//先弹出栈顶元素
		BiTreeStackNode* node = (BiTreeStackNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);

		//判断弹出的节点是否为空
		if (node->root == NULL) {
			continue;
		}
		if (node->flag == MY_TRUE) {
			printf("%c", node->root->ch);
		}
		else {
			/*
		//1.先序遍历
			//当前结点右结点入栈
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//当前结点左结点入栈
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
			//当前结点入栈
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
			*/

			/*
		//2.中序遍历
			//当前结点右结点入栈
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//当前结点入栈
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
			//当前结点左结点入栈
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
		    */

			
		//3.后序遍历
			//当前结点入栈
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
			//当前结点右结点入栈
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//当前结点左结点入栈
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
			
		}

	}
}

//二叉树的递归遍历
void Recursion(BinaryNode* root) {
	if (root == NULL) {
		return;
	}
	/*
//1.先序遍历
	//打印根节点
	printf("%c", root->ch);
	//打印左子树
	Recursion(root->lchild);
	//打印右子树
	Recursion(root->rchild);
	*/
	/*
//2.中序遍历
	//打印左子树
	Recursion(root->lchild);
	//打印根节点
	printf("%c", root->ch);
	//打印右子树
	Recursion(root->rchild);
	*/
	
//3.后序遍历
	//打印左子树
	Recursion(root->lchild);
	//打印右子树
	Recursion(root->rchild);
	//打印根节点
	printf("%c", root->ch);
	
}

void CreateBinaryTree() {
	//创建节点
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };

	//简历节点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	//二叉树的非递归遍历打印
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