#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while (i<j);
    // swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void QuickSort(int A[], int low, int high)
{
    int partitionIndex; // index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        QuickSort(A, low, partitionIndex - 1);  //  sort left subarray
        QuickSort(A, partitionIndex+1, high); // sort right subarray
    }
}

int main()
{
    int A[] = {12, 10, 1, 5, 2, 3, 20, 6};
    int n = 8;
    printArray(A, n);
    QuickSort(A, 0, n - 1);
    printArray(A,n);
    return 0;
}
