#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

/* 选择排序：相邻两个元素进行比较，把小的元素的下标记录下来，
一轮完整的比较之后，若最小值的下标不是i，则两个元素交换位置
*/
time_t getSystemTime() {
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//交换函数
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//打印函数
void PrintArray(int arr[], int length) {
for (int i = 0; i < length; i++) {
	printf("%d ", arr[i]);
}
printf("\n");
}

//选择排序
void SelectSort(int arr[], int length) {
	//选择排序减少交换次数
	for (int i = 0; i < length; i++) {
		int min = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		// 避免无意义的位置交换
		if (min != i) {
			Swap(&arr[min], &arr[i]);
		}
	}
		
}

int main(void) {

	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	printf("排序前：\n");
	PrintArray(arr, MAX);

	time_t t_start = getSystemTime();

	SelectSort(arr, MAX);

	time_t t_end = getSystemTime();

	printf("排序后：\n");
	PrintArray(arr, MAX);

	
	printf("选择排序%d个元素，所需时间：%lld ms\n", MAX, t_end - t_start);
	printf("\n");
	system("pause");
	return 0;
}
