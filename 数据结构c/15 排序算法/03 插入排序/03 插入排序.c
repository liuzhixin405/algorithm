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

//��ӡ����
void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��������
void InsertSort(int arr[], int length) {
	int i,j;
	for (i = 1; i < length; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];		//��������Ԫ���ó���
			for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
				//�Ƚϴ��Ԫ�����Ųһλ���ڳ��ռ�
				arr[j + 1] = arr[j];
			}
			//����
			arr[j + 1] = temp;
		}
	}
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

	InsertSort(arr, MAX);

	time_t t_end = getSystemTime();

	printf("�����\n");
	PrintArray(arr, MAX);

	printf("��������%d��Ԫ�أ�����ʱ�䣺%lld ms\n", MAX, t_end - t_start);
	printf("\n");
	system("pause");
	return 0;
}