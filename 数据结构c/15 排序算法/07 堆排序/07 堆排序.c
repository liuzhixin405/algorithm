#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

time_t getSystemTime() {
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//��������
int* CreateArray() {
	int* arr = (int*)malloc(sizeof(int) * MAX);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	return arr;
}

//��ӡ����
void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void MySwap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
/*
	@param myArr��������������
	@param index���������Ľ����±�
	@param len������ĳ���
*/
//�ѵ���
void HeapAdjust(int arr[],int index, int len) {
	//�ȱ��浱ǰ�����±ꣻ
	int max = index;
	//�������Һ��ӵ������±�(��0��ʼ)
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (lchild<len && arr[lchild]>arr[max]) {
		max = lchild;
	}
	if (rchild<len && arr[rchild]>arr[max]) {
		max = rchild;
	}

	if (max != index) {
		//�������ڵ�
		MySwap(arr, max, index);
		HeapAdjust(arr, max, len);
	}
}

//������
void HeapSort(int myArr[], int len) {
	//��ʼ����
	for (int i = len / 2 - 1; i >= 0; i--) {
		HeapAdjust(myArr, i, len);
	}
	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	for (int i = len - 1; i >= 0; i--) {
		MySwap(myArr, 0, i);
		HeapAdjust(myArr, 0, i);
	}
}
int main(void) {

	int* myArr = CreateArray();

	printf("����ǰ��\n");
	PrintArray(myArr, MAX);

	time_t t_start = getSystemTime();

	HeapSort(myArr, MAX);

	time_t t_end = getSystemTime();

	printf("�����\n");
	PrintArray(myArr, MAX);
	printf("������%d��Ԫ�أ�����ʱ�䣺%lld ms\n", MAX, t_end - t_start);

	free(myArr);
	printf("\n");
	system("pause");
	return 0;
}