#include <stdio.h>

void quicksort(int *arr, int low, int high);

int main()
{
    int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
    int size  = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, size);

    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    puts("");

    return 0;
}

void quicksort(int *arr, int low, int high)
{
    int i = low;
    int j = high-1;
    int temp;
    do
    {
        while (j > i)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                ++i;
                break;
            }
            --j;
        }
        while (i < j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                --j;
                break;
            }
            ++i;
        }
    } while (i < j);

    if(i < high-1)
        quicksort(arr, i+1, high);
    if (low < j-1)
        quicksort(arr, low, j);
}
