#include<iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];  // Choose the first element as the pivot
    int i = start + 1;       // Left pointer
    int j = end;             // Right pointer

    while (i <= j)
    {
        // Find element greater than the pivot
        while (i <= j && arr[i] < pivot)
            i++;

        // Find element smaller than or equal to the pivot
        while (i <= j && arr[j] >= pivot)
            j--;

        // Swap the elements if the left pointer is less than the right pointer
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot in its correct position
    int temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;

    // Return the partition index
    return j;
}

void quicksort(int *arr, int start, int end)
{
    if (start < end)
    {
        int partition_index = partition(arr, start, end);

        // Recursive calls for the two partitions
        quicksort(arr, start, partition_index - 1);
        quicksort(arr, partition_index + 1, end);
    }
}

int main()
{
    int size = 7;
    int arr[7] = {5, 1, 3, 10, 7, 14, 2};

    quicksort(arr, 0, size - 1);

    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }

    return 0;
}
