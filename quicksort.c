#include <stdio.h>

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            // swap
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    int tmp = array[i+1];
    array[i+1] = array[high];
    array[high] = tmp;

    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main()
{
    int arr[] = {8, 7, 2, 1, 0, 9, 6};

    int n = 7;                  //int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array : \n");
    for (int  i = 0; i < n ; i++)
    {
        printf(" %d ", arr[i]);
    }
    
}