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

//��������
void QuickSort(int arr[], int start, int end) {
	int i = start;
	int j = end;
	int temp = arr[start];		//��׼��
	if (i < j) {
		while (i < j) {
			//��������ȥ�ұȻ�׼��С��
			while (i < j && arr[j] >= temp) {
				j--;
			}
			//���
			if (i < j) {
				arr[i] = arr[j];
				i++;
			}
			//���������ұȻ�׼�������
			while (i < j && arr[i] < temp) {
				i++;
			}
			//���
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}
		}
		//�ѻ�׼���ŵ�iλ��
		arr[i] = temp;
		//����߲��ֽ��п�������
		QuickSort(arr, start, i - 1);
		//���ұ߲��ֽ��п�������
		QuickSort(arr, i+1, end);
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

	QuickSort(arr, 0, MAX-1);

	time_t t_end = getSystemTime();

	printf("�����\n");
	PrintArray(arr, MAX);

	printf("��������%d��Ԫ�أ�����ʱ�䣺%lld ms\n", MAX, t_end - t_start);
	printf("\n");
	system("pause");
	return 0;
}

