#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
单纯的先序遍历结果，中序遍历结果，后序遍历结果都无法还原一棵二叉树，
必须用中序结果+先序结果---或者中序结果+后序结果  两两结合才能还原一棵树

井号法创建树思想：
将一个树所有的结点都补成二叉，没有节点的地方用#代替，用先序遍历的结果还原一棵二叉树

*/

//二叉树结点
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;

}BinaryNode;

//递归打印,先序遍历
void Recursion(BinaryNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

//创建树
BinaryNode* CreateBinaryTree() {
	//清空输入缓冲区
	fflush(stdin);
	char ch;
	
	scanf("%c", &ch);

	BinaryNode* node;

	if (ch == '#') {
		node = NULL;
	}
	else{
		//创建根节点
		node = (BinaryNode*)malloc(sizeof(BinaryNode));
		if (node == NULL)
		{
			return NULL;
		}
		node->ch = ch;
		node->lchild = CreateBinaryTree();
		node->rchild = CreateBinaryTree();

	}
	return node;
}

/*释放内存*/
void FreeTree(BinaryNode* T)
{
	if (T != NULL)
	{
		if (T->lchild != NULL)
		{
			FreeTree(T->lchild);//递归释放左子树
			T->lchild = NULL;
		}
		if (T->rchild != NULL)
		{
			FreeTree(T->rchild);
			T->rchild = NULL;
		}
		free(T);
		T = NULL;
	}
}

int main(void) {
	//创建树
	printf("以#截止，输入二叉树的结点数据(无回车、空格):\n");
	BinaryNode* root = CreateBinaryTree();
	//打印树
	Recursion(root);
	FreeTree(root);

	printf("\n");
	system("pause");
	return 0;
}
