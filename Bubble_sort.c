#include<stdio.h>
#include<stdlib.h>

void printArray(int A[],int size){
    for(int i=0;i<size;i++){
        printf("%d\n",A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[],int size){
    int temp=0;
    int isSort=0; //to check if the array is already sorted or not
    for (int i = 0; i < size-1; i++)//for number of pass
    {
        printf("Working on pass number %d\n",i+1);
        isSort=1;
        for (int j = 0; j < size-1-i; j++)//for comparision in each pass
        {
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSort=0; 
            }
        }
        if(isSort){
            return; //terminate the loop if isSort value remains 1;
        }
    }
    
}

int main()
{
    // int A[]={1,5,2,10,3,4};
    int A2[]={1,2,3,4,5,6};
    int n=6;
    printArray(A2,n);// printing array before sorting
    bubbleSort(A2,n);// function to sort the array
    printArray(A2,n);// printing array after sorting
    return 0;
}
