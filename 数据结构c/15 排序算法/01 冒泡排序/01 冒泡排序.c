#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

/*time_t��һ�������ͣ�һ��������ʾ��1970������������,�����Ͷ�����<sys/time.h>��.
struct timeb�ṹ: ��Ҫ��������Ա, һ������, ��һ���Ǻ���, ��ȷ��Ϊ����.
struct timeb
{
	time_t time;
	unsigned short millitm;
	short timezone;
	short dstflag;
};
�ɺ���int ftime(struct timeb *tp); ����ȡtimeb.
*/
time_t getSystemTime() {
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//��������
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//ð������
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
	printf("����ǰ��\n");
	PrintArray(arr, MAX);

	time_t t_start = getSystemTime();

	BubbleSort(arr, MAX);

	time_t t_end = getSystemTime();

	printf("�����\n");
	PrintArray(arr, MAX);

	printf("ð������%d��Ԫ�أ�����ʱ�䣺%lld ms\n", MAX, t_end - t_start);
	printf("\n");
	system("pause");
	return 0;
}
