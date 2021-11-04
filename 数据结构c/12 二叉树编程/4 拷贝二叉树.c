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
   我们可以递归的计算出左子树的高度和右子树的高度，
   然后取二者的最大值加1最为这棵二叉树的高度。
*/
//二叉树结点
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;

}BinaryNode;

//遍历二叉树
void Recursion1(BinaryNode* root) {
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
}

//拷贝二叉树
BinaryNode* CopyBinaryTree(BinaryNode* root) {
	if (root == NULL) {
		return NULL;
	}
	//拷贝左子树
	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	//拷贝右子树
	BinaryNode* rchild = CopyBinaryTree(root->rchild);

	//创建结点
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;
}

//释放二叉树内存
void FreeSpaceBinaryTree(BinaryNode* root) {
	if (root == NULL) {
		return;
	}
	//释放左子树
	FreeSpaceBinaryTree(root->lchild);
	//释放右子树
	FreeSpaceBinaryTree(root->rchild);

	//释放当前结点
	free(root);
}

void CreateBinaryTree4() {
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

	BinaryNode* root = CopyBinaryTree(&node1);
	Recursion1(root);
	FreeSpaceBinaryTree(root);
}

int main(void) {

	CreateBinaryTree4();

	printf("\n");
	system("pause");
	return 0;
}