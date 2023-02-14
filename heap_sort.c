#include <stdio.h>
#define MAX 100
void heap_sort(int arr[], int n);
void buildheap(int arr[], int n);
int del_root(int arr[], int *size);
void restoreDown(int arr[], int i, int size);
main()
{

    int i, n, arr[MAX];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {

        printf("Enter element %d : ", i);
        scanf("%d", &arr[i]);
    }
    heap_sort(arr, n);
    printf("\nSorted list is :\n");
    for (i = 0; i < n; i++)

        printf("%d ", arr[i]);

    printf("\n");
}

void buildHeap(int arr[], int size)
{

    int i;
    for (i = size / 2; i >= 1; i--)

        restoreDown(arr, i, size);
}
void heap_sort(int arr[], int size)
{

    int max;
    buildHeap(arr, size);
    printf("Heap is : ");
    display(arr, size);
    while (size > 1)
    {

        max = del_root(arr, &size);
        arr[size + 1] = max;
    }
}
int del_root(int arr[], int *size)
{
    int max = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    restoreDown(arr, 1, *size);
    return max;
}
void restoreDown(int arr[], int i, int size)
{
    int left = 2 * i, right = left + 1;
    int num = arr[i];
    while (right <= size)
    {

        if (num >= arr[left] && num >= arr[right])
        {

            arr[i] = num;
            return;
        }
        else if (arr[left] > arr[right])
        {
            arr[i] = arr[left];
            i = left;
        }
        else
        {

            arr[i] = arr[right];
            i = right;
        }
        left = 2 * i;
        right = left + 1;
    }
    if (left == size && num < arr[left])
    {

        arr[i] = arr[left];
        i = left;
    }
    arr[i] = num;
}