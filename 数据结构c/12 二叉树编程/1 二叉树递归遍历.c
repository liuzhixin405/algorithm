#define _CRT_SECURE_NO_WARNINGS
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
*/
//二叉树结点
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;

}BinaryNode;
//递归遍历
void Recursion(BinaryNode* root) {
	if (root == NULL) {
		return;
	}

//1.先序遍历
	//先访问根节点
	printf("%c", root->ch);
	//再遍历左子树
	Recursion(root->lchild);
	//再遍历右子树
	Recursion(root->rchild);
	/*
//2.中序遍历
	//再遍历左子树
	Recursion(root->lchild);
	//先访问根节点
	printf("%c", root->ch);
	//再遍历右子树
	Recursion(root->rchild);
	*/
	/*
//3.后序遍历
	//再遍历左子树
	Recursion(root->lchild);
	//再遍历右子树
	Recursion(root->rchild);
	//先访问根节点
	printf("%c", root->ch);
	*/
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

	//遍历递归
	Recursion(&node1);
	printf("\n");
}

int main_01(void) {

	CreateBinaryTree();

	printf("\n");
	system("pause");
	return 0;
}