#include <iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;


struct Arr {
	int* pBase;
	int len;
	int cnt;
};

void init_arr(struct Arr* pArr, int length);
bool arr_empty(struct Arr* pArr);
void show_arr(struct Arr* pArr);
bool is_full(struct Arr* pArr);
bool append_arr(struct Arr* pArr, int val);
bool insert_arr(struct Arr* pArr, int pos, int val);
bool delete_arr(struct Arr* pArr, int pos, int* pVal);
void sort_arr(struct Arr* pArr);
void inversion_arr(struct Arr* pArr);



int main() {
	struct Arr arr;
	init_arr(&arr, 7);
	printf("数组长度:%d\n", arr.len);
	show_arr(&arr);

	printf("准备插入\n");
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	append_arr(&arr, 6);
	insert_arr(&arr, 7, 12);
	int val;
	if (delete_arr(&arr, 8, &val)) {
		printf("删除成功\n");
		printf("已经被删除掉的元素是:%d\n", val);
	}
	else {
		printf("删除失败\n");
	}
	show_arr(&arr);
	printf("倒置\n");
	inversion_arr(&arr);
	show_arr(&arr);
	printf("排序\n");
	sort_arr(&arr);
	show_arr(&arr);
	return 0;
}

void init_arr(struct Arr* pArr, int length) {

	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase) {
		std::cout << "分配内存失败" << std::endl;
		exit(-1);
	}
	else {
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool arr_empty(struct Arr* pArr)
{
	if (pArr->cnt == 0)
		return true;
	else
		return false;
}

void show_arr(struct Arr* pArr)
{
	if (arr_empty(pArr))
	{
		printf("数组是空\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; ++i)
		{
			printf("%d  ", pArr->pBase[i]);
			printf("\n");
		}
	}
}

bool is_full(struct Arr* pArr) {
	if (pArr->cnt == pArr->len) {
		printf("数组已满\n");
		return true;
	}
	return false;
}

bool append_arr(struct Arr* pArr, int val) {
	if (is_full(pArr))
		return false;
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;

}
bool insert_arr(struct Arr* pArr, int pos, int val) {
	if (is_full(pArr))
		return false;
	if (pos <1 || pos >pArr->cnt + 1)
		return false;
	if (pos == pArr->cnt) {
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt++;
	}
	else {
		for (int i = pArr->cnt - 1; i >= pos - 1; i--) {
			pArr->pBase[i + 1] = pArr->pBase[i];
		}
		pArr->pBase[pos - 1] = val;
		pArr->cnt++;
	}
	return true;
}

/// <summary>
/// 1,2,3,4   pos=2  
/// </summary>
/// <param name="pArr"></param>
/// <param name="pos"></param>
/// <param name="pVal"></param>
/// <returns></returns>

bool delete_arr(struct Arr* pArr, int pos, int* pVal) {
	int i;
	if (arr_empty(pArr))
		return false;
	if (pos <1 || pos > pArr->cnt)
		return false;
	*pVal = pArr->pBase[pos - 1];
	for (i = pos; i < pArr->cnt; i++)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;

}

void inversion_arr(struct Arr* pArr) {
	int i = 0;
	int j = pArr->cnt - 1;
	int t;
	while (i < j) {
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr* pArr) {

	int i, j, t;
	for ( i = 0; i < pArr->cnt; i++)
	{
		for (j = i + 1; j < pArr->cnt; j++) {
			if (pArr->pBase[i] > pArr->pBase[j]) {
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[i];
				pArr->pBase[i] = t;
			}
		}
	}
}