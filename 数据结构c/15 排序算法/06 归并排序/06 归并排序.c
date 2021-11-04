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
int* CreateArray() {
	int* arr = (int*)malloc(sizeof(int) * MAX);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	return arr;
}

//�ϲ��㷨 ��С����
void Merge(int arr[], int start, int end, int mid, int* temp) {
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//�����ռ�Ԫ�ظ���
	int length = 0;

	//�ϲ�������������
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
	//i�������
	while (i_start <= i_end) {
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j�������
	while (j_start <= j_end) {
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}

	//�����ռ串�ǵ�ԭ�ռ�
	for (int i = 0; i < length; i++) {
		arr[start + i] = temp[i];
	}

}

//�鲢����
void MergeSort(int arr[], int start, int end, int* temp) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	//����
	//����
	MergeSort(arr, start, mid, temp);
	//�Ұ��
	MergeSort(arr, mid+1, end, temp);
	//�ϲ�
	Merge(arr, start, end, mid, temp);
}

int main(void) {

	int* myArr = CreateArray();
	printf("����ǰ��\n");
	PrintArray(myArr, MAX);

	//�����ռ�
	int* temp = (int*)malloc(sizeof(int) * MAX);

	time_t t_start = getSystemTime();

	MergeSort(myArr, 0, MAX-1, temp);
	
	time_t t_end = getSystemTime();

	printf("�����\n");
	PrintArray(myArr, MAX);
	printf("�鲢����%d��Ԫ�أ�����ʱ�䣺%lld ms\n", MAX, t_end - t_start);

	//�ͷſռ�
	free(temp);
	free(myArr);
	printf("\n");
	system("pause");
	return 0;
}