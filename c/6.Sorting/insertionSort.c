//
// Created by Aayush Kumar on 20/07/23.
//

#include<stdio.h>

void printArray(int*a, int n){
    for(int i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void insertionSort(int *a, int n){
    int key,j;
    //loop for passes
    for(int i=1; i<=n-1; i++){
        key=a[i];
        j=i-1;
        printf("working on pass %d\n",i);
        //loop for each pass
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int A[]={487,675,78,34,678,35};
    int n = 6;
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);
    return 0;
}

