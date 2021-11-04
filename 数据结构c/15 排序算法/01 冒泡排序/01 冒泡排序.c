#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

/*time_t是一个长整型，一般用来表示用1970年以来的秒数,该类型定义在<sys/time.h>中.
struct timeb结构: 主要有两个成员, 一个是秒, 另一个是毫秒, 精确度为毫秒.
struct timeb
{
	time_t time;
	unsigned short millitm;
	short timezone;
	short dstflag;
};
由函数int ftime(struct timeb *tp); 来获取timeb.
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
//冒泡排序
void BubbleSort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[i]) {
				Swap(&arr[i], &arr[j]);
			}
		}
	}
}

void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
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

	BubbleSort(arr, MAX);

	time_t t_end = getSystemTime();

	printf("排序后：\n");
	PrintArray(arr, MAX);

	printf("冒泡排序%d个元素，所需时间：%lld ms\n", MAX, t_end - t_start);
	printf("\n");
	system("pause");
	return 0;
}
