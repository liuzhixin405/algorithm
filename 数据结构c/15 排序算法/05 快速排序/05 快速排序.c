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

void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//快速排序
void QuickSort(int arr[], int start, int end) {
	int i = start;
	int j = end;
	int temp = arr[start];		//基准数
	if (i < j) {
		while (i < j) {
			//从右向左去找比基准数小的
			while (i < j && arr[j] >= temp) {
				j--;
			}
			//填坑
			if (i < j) {
				arr[i] = arr[j];
				i++;
			}
			//从左向右找比基准数大的数
			while (i < j && arr[i] < temp) {
				i++;
			}
			//填坑
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}
		}
		//把基准数放到i位置
		arr[i] = temp;
		//对左边部分进行快速排序
		QuickSort(arr, start, i - 1);
		//对右边部分进行快速排序
		QuickSort(arr, i+1, end);
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

	QuickSort(arr, 0, MAX-1);

	time_t t_end = getSystemTime();

	printf("排序后：\n");
	PrintArray(arr, MAX);

	printf("快速排序%d个元素，所需时间：%lld ms\n", MAX, t_end - t_start);
	printf("\n");
	system("pause");
	return 0;
}

