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

//创建数组
int* CreateArray() {
	int* arr = (int*)malloc(sizeof(int) * MAX);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	return arr;
}

//打印函数
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
	@param myArr：待调整的数组
	@param index：待调整的结点的下标
	@param len：数组的长度
*/
//堆调整
void HeapAdjust(int arr[],int index, int len) {
	//先保存当前结点的下标；
	int max = index;
	//保存左右孩子的数组下标(从0开始)
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (lchild<len && arr[lchild]>arr[max]) {
		max = lchild;
	}
	if (rchild<len && arr[rchild]>arr[max]) {
		max = rchild;
	}

	if (max != index) {
		//交换两节点
		MySwap(arr, max, index);
		HeapAdjust(arr, max, len);
	}
}

//堆排序
void HeapSort(int myArr[], int len) {
	//初始化堆
	for (int i = len / 2 - 1; i >= 0; i--) {
		HeapAdjust(myArr, i, len);
	}
	//交换堆顶元素和最后一个元素
	for (int i = len - 1; i >= 0; i--) {
		MySwap(myArr, 0, i);
		HeapAdjust(myArr, 0, i);
	}
}
int main(void) {

	int* myArr = CreateArray();

	printf("排序前：\n");
	PrintArray(myArr, MAX);

	time_t t_start = getSystemTime();

	HeapSort(myArr, MAX);

	time_t t_end = getSystemTime();

	printf("排序后：\n");
	PrintArray(myArr, MAX);
	printf("堆排序%d个元素，所需时间：%lld ms\n", MAX, t_end - t_start);

	free(myArr);
	printf("\n");
	system("pause");
	return 0;
}