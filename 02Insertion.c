#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int n){
    // code for traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[],int size,int element,int capacity,int index){
    // code for insertion
    if (size>=capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
int indDeletion(int arr[],int size,int index){
    int temp;
    if (index==size-1){
        temp=arr[index];
        return arr,size-1;
    }
    temp=arr[index];
    for (int i = index; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    return arr,size-1;
}
int main()
{
    int arr[100]={7,8,12,27,88};
    int size=5,element=45,index=2;
    display(arr,size);
    // indInsertion(arr,size,element,100,index);
    // size+=1;
    // display(arr,size);
    arr,size=indDeletion(arr,size,index);
    display(arr,size);
    return 0;

}
