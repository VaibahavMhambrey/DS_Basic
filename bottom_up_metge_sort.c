#include <stdio.h>
#define MAX 100
void merge_sort(int arr[], int n);
void merge_pass(int arr[], int temp[], int size, int n);
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2);
main()
{

    int i, n, arr[MAX];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, n);
    printf("\nSorted list is :\n");
    for (i = 0; i < n; i++)

        printf("%d ", arr[i]);

    printf("\n");
}

void merge_sort(int arr[], int n)
{

    int size = 1;
    int temp[MAX];
    while (size < n)
    {

        merge_pass(arr, temp, size, n);
        size = size * 2;
        merge_pass(temp, arr, size, n);
        size = size * 2;
    }
}
void merge_pass(int arr[], int temp[], int size, int n)
{

    int i, low1, up1, low2, up2;
    low1 = 0;
    while (low1 + size < n)
    {

        up1 = low1 + size - 1;
        low2 = low1 + size;
        up2 = low2 + size - 1;
        if (up2 >= n)

            up2 = n - 1;

        merge(arr, temp, low1, up1, low2, up2);
        low1 = up2 + 1;
    }
    for (i = low1; i <= n - 1; i++)
        temp[i] = arr[i];
}
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2)
{

    int i = low1;
    int j = low2;
    int k = low1;
    while ((i <= up1) && (j <= up2))
    {
        if (arr[i] <= arr[j])

            temp[k++] = arr[i++];

        else

            temp[k++] = arr[j++];
    }
    while (i <= up1)

        temp[k++] = arr[i++];

    while (j <= up2)

        temp[k++] = arr[j++];
}