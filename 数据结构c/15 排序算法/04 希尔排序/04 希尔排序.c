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

//��������
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

//ϣ������
void ShellSort(int arr[], int length) {
	int increasement = length;		//����
	int i, j, k;
	//ע�⣺����Ϊ1ʱ��Ҫ����һ�β�������
	do{
		//ȷ�����������
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
	printf("����ǰ��\n");
	//PrintArray(arr, MAX);

	time_t t_start = getSystemTime();

	ShellSort(arr, MAX);

	time_t t_end = getSystemTime();

	printf("�����\n");
	//PrintArray(arr, MAX);
	
	printf("ϣ������%d��Ԫ�أ�����ʱ�䣺%lld ms\n", MAX, t_end - t_start);

	printf("\n");
	system("pause");
	return 0;
}