#define _CRT_SECURE_NO_WARNIGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "DynamicArray.h"

void test01(){
	//��ʼ����̬����
	Dynamic_Array* myArray = Init_Array();
	//��ӡ����
	printf("����������%d\n", Capacity_Array(myArray));
	printf("�����С��%d\n", Size_Array(myArray));
	//����Ԫ��
	for(int i = 0; i < 30; i++){
		Push_Back_Array(myArray, i);
	}
	printf("����������%d\n", Capacity_Array(myArray));
	printf("�����С��%d\n", Size_Array(myArray));
	//��ӡ
	Print_Array(myArray);
	//ɾ��
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 27);
	//��ӡ
	Print_Array(myArray);
	//����5��λ��
	int pos = Find_Array(myArray, 5);
	printf("���ҵ�5��λ�õ��±�(posֵ):%d��ֵ: %d\n", pos, At_Array(myArray, pos));
	//����
	FreeSpace_Array(myArray);
}

int main(void) {
	
	test01();
	system("pause");
	return 0;
}