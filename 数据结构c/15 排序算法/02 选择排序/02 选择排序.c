#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

/* ѡ��������������Ԫ�ؽ��бȽϣ���С��Ԫ�ص��±��¼������
һ�������ıȽ�֮������Сֵ���±겻��i��������Ԫ�ؽ���λ��
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

//��ӡ����
void PrintArray(int arr[], int length) {
for (int i = 0; i < length; i++) {
	printf("%d ", arr[i]);
}
printf("\n");
}

//ѡ������
void SelectSort(int arr[], int length) {
	//ѡ��������ٽ�������
	for (int i = 0; i < length; i++) {
		int min = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		// �����������λ�ý���
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
	printf("����ǰ��\n");
	PrintArray(arr, MAX);

	time_t t_start = getSystemTime();

	SelectSort(arr, MAX);

	time_t t_end = getSystemTime();

	printf("�����\n");
	PrintArray(arr, MAX);

	
	printf("ѡ������%d��Ԫ�أ�����ʱ�䣺%lld ms\n", MAX, t_end - t_start);
	printf("\n");
	system("pause");
	return 0;
}
