#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10000

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

void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//希尔排序
void ShellSort(int arr[], int length) {
	int increasement = length;		//增量
	int i, j, k;
	//注意：增量为1时还要进行一次插入排序
	do{
		//确定分组的增量
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++) {

			for (j = i + increasement; j < length; j += increasement) {
				if (arr[j] < arr[j - increasement]) {
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);
}

int main(void) {

	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	printf("排序前：\n");
	//PrintArray(arr, MAX);

	time_t t_start = getSystemTime();

	ShellSort(arr, MAX);

	time_t t_end = getSystemTime();

	printf("排序后：\n");
	//PrintArray(arr, MAX);
	
	printf("希尔排序%d个元素，所需时间：%lld ms\n", MAX, t_end - t_start);

	printf("\n");
	system("pause");
	return 0;
}