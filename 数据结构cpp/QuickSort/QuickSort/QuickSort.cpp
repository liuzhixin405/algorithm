#include<stdio.h>

int FindPos(int * a, int low, int high);
void QuickSort(int *a, int low, int high);

int main()
{
    int arr[8] = {2,4,1,5,7,6,8,0};
   
    int i;
    QuickSort(arr, 0, 7);
    for (i = 0; i < 8; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 1;
}


void QuickSort(int * a, int low, int high) {
    int pos;
    if (low < high) {
        pos = FindPos(a, low, high);
        QuickSort(a, low, pos - 1);
        QuickSort(a, pos + 1, high);
    }
}

int FindPos(int *a, int low, int high) {
    int val = a[low];
    while (low < high) 
    {
        while (low < high && a[high] >= val)
            --high;
        a[low] = a[high];
        while(low < high&& a[low] <= val)
            ++low;
        a[high = a[low]];
    } //循环结束后 low=high
    a[low] = val;
    return low;
}