#include <iostream>
#include<malloc.h>


struct BTNode
{
	int data;
	struct BTNode* pLchild;
	struct BTNode* pRchild;
};

struct BTNode* CreateBTree();
void PreTraverseBTree(struct BTNode* pT);
void InTraverseBTree(struct BTNode* pT);
void PostTraverseBTree(struct BTNode* pT);
int main()
{
	struct BTNode* pT = CreateBTree();
	printf("先序->\n");
	PreTraverseBTree(pT);
	printf("中序->\n");
	InTraverseBTree(pT);
	printf("后续->\n");
	PostTraverseBTree(pT);
}

struct BTNode * CreateBTree()
{
	struct BTNode* pA = (struct BTNode*)malloc(sizeof(BTNode));
	struct BTNode* pB = (struct BTNode*)malloc(sizeof(BTNode));
	struct BTNode* pC = (struct BTNode*)malloc(sizeof(BTNode));
	struct BTNode* pD = (struct BTNode*)malloc(sizeof(BTNode));
	struct BTNode* pE = (struct BTNode*)malloc(sizeof(BTNode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild=NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;
	return pA;
}
void PreTraverseBTree(struct BTNode* pT) 
{
	if (pT != NULL) {
		printf("%c\n", pT->data);
		if(pT->pLchild!=NULL)
		PreTraverseBTree(pT->pLchild);
		if(pT->pRchild!=NULL)
		PreTraverseBTree(pT->pRchild);
	}
}
void InTraverseBTree(struct BTNode* pT) {
	if (pT != NULL) {
		
		if (pT->pLchild != NULL)
			PreTraverseBTree(pT->pLchild);
		printf("%c\n", pT->data);
		if (pT->pRchild != NULL)
			PreTraverseBTree(pT->pRchild);
	}
}

void PostTraverseBTree(struct BTNode* pT) {
	if (pT != NULL) {

		if (pT->pLchild != NULL)
			PreTraverseBTree(pT->pLchild);
		if (pT->pRchild != NULL)
			PreTraverseBTree(pT->pRchild);
		printf("%c\n", pT->data);

	}
}