#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
}

void InsertionSort(int A[], int n)
{
    int key,j;
    for (int i = 1; i < n; i++)// loop for passes
    {
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}


int main()
{
    int A[] = {1, 2, 6, 10, 3, 5};
    int n = 6;
    printArray(A, n);
    InsertionSort(A, n);
    printArray(A, n);
    return 0;
}
