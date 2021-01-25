#include<stdio.h>
#include<stdlib.h>

void printArray(int A[],int n){
    for(int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }
    printf("\n");
}

void SelectionSort(int A[],int n){
    int indexMin,temp;
    printf("Running Selection Sort ....\n");
    for (int i = 0; i < n-1; i++)
    {
        indexMin=i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexMin]){
                indexMin=j;
            }
        }
        // swap A[i] and A[indexMin]
        temp=A[i];
        A[i]=A[indexMin];
        A[indexMin]=temp;
    }
    
}

int main()
{
    int A[]={5,10,1,2,20,3};
    int n=6;
    printArray(A,n);
    SelectionSort(A,n);
    printArray(A,n);
    return 0;
}
