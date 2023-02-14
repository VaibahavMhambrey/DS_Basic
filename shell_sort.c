#include <stdio.h>
#define MAX 100
main()
{

    int arr[MAX], i, j, n, k, incr;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter maximum increment (odd value) : ");
    scanf("%d", &incr);

    while (incr >= 1)
    {

        for (i = incr; i < n; i++)
        {
            k = arr[i];
            for (j = i - incr; j >= 0 && k < arr[j]; j = j - incr)

                arr[j + incr] = arr[j];

            arr[j + incr] = k;
        }
        incr = incr - 2;
    }
    printf("Sorted list is : \n");
    for (i = 0; i < n; i++)

        printf("%d ", arr[i]);

    printf("\n");
}