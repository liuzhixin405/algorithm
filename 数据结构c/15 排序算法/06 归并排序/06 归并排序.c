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

//打印函数
void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
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

//合并算法 从小到大
void Merge(int arr[], int start, int end, int mid, int* temp) {
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//辅助空间元素个数
	int length = 0;

	//合并两个有序序列
	while (i_start<=i_end && j_start<=j_end)
	{
		if (arr[i_start] < arr[j_start]) {
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else {
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	//i这个序列
	while (i_start <= i_end) {
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j这个序列
	while (j_start <= j_end) {
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}

	//辅助空间覆盖到原空间
	for (int i = 0; i < length; i++) {
		arr[start + i] = temp[i];
	}

}

//归并排序
void MergeSort(int arr[], int start, int end, int* temp) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	//分组
	//左半边
	MergeSort(arr, start, mid, temp);
	//右半边
	MergeSort(arr, mid+1, end, temp);
	//合并
	Merge(arr, start, end, mid, temp);
}

int main(void) {

	int* myArr = CreateArray();
	printf("排序前：\n");
	PrintArray(myArr, MAX);

	//辅助空间
	int* temp = (int*)malloc(sizeof(int) * MAX);

	time_t t_start = getSystemTime();

	MergeSort(myArr, 0, MAX-1, temp);
	
	time_t t_end = getSystemTime();

	printf("排序后：\n");
	PrintArray(myArr, MAX);
	printf("归并排序%d个元素，所需时间：%lld ms\n", MAX, t_end - t_start);

	//释放空间
	free(temp);
	free(myArr);
	printf("\n");
	system("pause");
	return 0;
}