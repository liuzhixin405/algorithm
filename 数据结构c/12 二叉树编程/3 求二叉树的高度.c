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


int CaculateHeight(BinaryNode* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		// �����������ĸ߶Ⱥ��������ĸ߶� 
		int lHeight = CaculateHeight(root->lchild);
		int rHeight = CaculateHeight(root->rchild);
		// ���ض��߽ϴ��߼�1 
		if (lHeight > rHeight)
			return(lHeight + 1);
		else 
			return(rHeight + 1);
	}
}
void CreateBinaryTree3() {
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

	int height = CaculateHeight(&node1);
	
	printf("�˶������ĸ߶ȣ�%d\n", height);
}

int main_03(void) {

	CreateBinaryTree3();

	printf("\n");
	system("pause");
	return 0;
}