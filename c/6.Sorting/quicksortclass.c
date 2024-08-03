//
// Created by Aayush Kumar on 24/08/23.
//
#include<stdio.h>
int count=0;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[],int low, int high){
    int i=low;
    int j=high;
    int pivot = A[i];
    int p=i;
    for(int q=i+1; q<=j; q++){
        if(A[q]<=pivot){
            p++;
            int temp = A[p];
            A[p]= A[q];
            A[q]=temp;
            count++;
        }
    }
    int temp = A[p];
    A[p]= A[i];
    A[i]=temp;
    count++;
    return p;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}
int main(){
    int A[]={5,6,8,7,2,1,4,3};
    int n = 8;
    printArray(A,n);
    quickSort(A,0,n-1);
    printArray(A,n);
    printf("%d",count);
    return 0;
}
