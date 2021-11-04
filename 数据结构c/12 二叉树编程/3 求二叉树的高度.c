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


int CaculateHeight(BinaryNode* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		// 计算左子树的高度和右子树的高度 
		int lHeight = CaculateHeight(root->lchild);
		int rHeight = CaculateHeight(root->rchild);
		// 返回二者较大者加1 
		if (lHeight > rHeight)
			return(lHeight + 1);
		else 
			return(rHeight + 1);
	}
}
void CreateBinaryTree3() {
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

	int height = CaculateHeight(&node1);
	
	printf("此二叉树的高度：%d\n", height);
}

int main_03(void) {

	CreateBinaryTree3();

	printf("\n");
	system("pause");
	return 0;
}