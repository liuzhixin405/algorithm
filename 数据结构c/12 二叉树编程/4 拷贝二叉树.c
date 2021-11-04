#define _CRT_SECURE_NO_WARNINGS
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

//����������
void Recursion1(BinaryNode* root) {
	if (root == NULL) {
		return;
	}

	//1.�������
		//�ȷ��ʸ��ڵ�
	printf("%c", root->ch);
	//�ٱ���������
	Recursion(root->lchild);
	//�ٱ���������
	Recursion(root->rchild);
}

//����������
BinaryNode* CopyBinaryTree(BinaryNode* root) {
	if (root == NULL) {
		return NULL;
	}
	//����������
	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	//����������
	BinaryNode* rchild = CopyBinaryTree(root->rchild);

	//�������
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;
}

//�ͷŶ������ڴ�
void FreeSpaceBinaryTree(BinaryNode* root) {
	if (root == NULL) {
		return;
	}
	//�ͷ�������
	FreeSpaceBinaryTree(root->lchild);
	//�ͷ�������
	FreeSpaceBinaryTree(root->rchild);

	//�ͷŵ�ǰ���
	free(root);
}

void CreateBinaryTree4() {
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