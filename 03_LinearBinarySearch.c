#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low=0;
    high=size-1;
    // start searching
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            high = mid - 1;
        }
    }
    // searching ends
    return -1;
}
int main()
{
    // unsorted array for linear search
    // int arr[] = {11, 2, 3, 14, 5, 6, 17, 8, 9, 10};
    // int size = sizeof(arr) / sizeof(int);

    // sorted array for binary search
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int element = 1;
    int searchindex = binarySearch(arr, size, element);
    printf("The element %d was at index %d\n", element, searchindex);
    return 0;
}
