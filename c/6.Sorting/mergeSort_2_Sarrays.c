//
// Created by Aayush Kumar on 13/08/23.
//


#include<stdio.h>
#include<stdlib.h>

void printArray(int *C, int size){
    for(int i=0; i<size; i++){
        printf("%d ",C[i]);
    }
    printf("\n");
}

void merge(int C[], int mid, int low, int high){
    int i, j, k, B[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(C[i]<C[j]){
            B[k]=C[i];
            i++;
            k++;
        }
        else{
            B[k]=C[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=C[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k]=C[j];
        j++;
        k++;
    }
    for(int i=low; i<=high; i++){
        C[i]=B[i];
    }
}

void mergeSort(int A[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(A, low, mid );
        mergeSort(A, mid+1, high );
        merge(A,mid, low, high);
    }
}

int main(){
    int A[4] = {2,4,5,7};
    int B[4] = {11,45,67,89};
    int* C = (int *) malloc((500)*sizeof(int));
    int size = sizeof(C)/ sizeof(int);
    int i;
    for(i=0; i<size[[C]]; i++){
        if(i>=A)
            C[i]=B[i];
        else{
            C[i]=A[i];
        }
    }
    mergeSort(C, 2, 89);
    printArray(C,size);
    return 0;
}
