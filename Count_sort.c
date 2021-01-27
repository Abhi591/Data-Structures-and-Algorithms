#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maximum(int A[],int n){
    int max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(max < A[i]){
            max=A[i];
        }
    }
    return max;
}
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void countSort(int A[],int n){
    int i,j;
    //  find the maximum number
    int max=maximum(A,n);
    // create the count array
    int * count=(int *)malloc((max+1)*sizeof(int));
    //initialize the array elements are 0
    for (i = 0; i < max+1; i++)
    {
        count[i]=0;
    }
    for (i = 0; i < n; i++)
    {
        count[A[i]]=count[A[i]]+1;
    }
    i=0; // counter for count array
    j=0; // counter for given array

    while (i<=max)
    {
        if(count[i] > 0){
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
    
}

int main()
{
    int A[]={5,10,1,4,2,9};
    int n=6;
    printArray(A,n);
    countSort(A,n);
    printArray(A,n);
    return 0;
}
