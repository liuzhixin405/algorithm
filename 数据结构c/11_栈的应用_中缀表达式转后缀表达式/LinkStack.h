#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>

//��ʽջ�Ľ��
typedef struct LINKNODE {
	struct LINKNODE* next;
}LinkNode;
//��ʽջ
typedef struct LINKSTACK {
	LinkNode head;
	int size;
}LinkStack;

//��ʼ������
LinkStack* Init_LinkStack();
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//��ջ
void Pop_LinkStack(LinkStack* stack);
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);
//����ջԪ�صĸ���
int Size_LinkStack(LinkStack* stack);
//���ջ
void clear_LinkStack(LinkStack* stack);
//����ջ
void FreeSpace_LinkStack(LinkStack* stack);

#endif // !LINKSTACK_H

