#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
�������������������������������������������޷���ԭһ�ö�������
������������+������---����������+������  ������ϲ��ܻ�ԭһ����

���ŷ�������˼�룺
��һ�������еĽ�㶼���ɶ��棬û�нڵ�ĵط���#���棬����������Ľ����ԭһ�ö�����

*/

//���������
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;

}BinaryNode;

//�ݹ��ӡ,�������
void Recursion(BinaryNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

//������
BinaryNode* CreateBinaryTree() {
	//������뻺����
	fflush(stdin);
	char ch;
	
	scanf("%c", &ch);

	BinaryNode* node;

	if (ch == '#') {
		node = NULL;
	}
	else{
		//�������ڵ�
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

/*�ͷ��ڴ�*/
void FreeTree(BinaryNode* T)
{
	if (T != NULL)
	{
		if (T->lchild != NULL)
		{
			FreeTree(T->lchild);//�ݹ��ͷ�������
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
	//������
	printf("��#��ֹ������������Ľ������(�޻س����ո�):\n");
	BinaryNode* root = CreateBinaryTree();
	//��ӡ��
	Recursion(root);
	FreeTree(root);

	printf("\n");
	system("pause");
	return 0;
}
