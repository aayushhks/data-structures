//
// Created by Aayush Kumar on 18/07/23.
//

#include<stdio.h>

void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d %t",a[i]);
    }
    printf("\n");
}

void bubbleSort_with_BestCase(int *a, int n){
    int temp;
    int isSorted=0;
    for(int i=0 ; i<n-1 ; i++){
        printf("working on pass %d\n",i+1);
        isSorted=1;
        for(int j=0 ; j<n-i-1 ; j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                isSorted=0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

void bubbleSortNormal(int *a, int n){
    int temp;
    // loop  for passes
    for(int i=0 ; i<n-1 ; i++){
        printf("working on pass number %d\n",i+1);
        for(int j=0 ; j<n-i-1 ; j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
//    int A[]={7,11,9, 2, 17, 4};
    int A[]={2,1,3,4,5,6};
    int N = 6;
    printArray(A,N);
    bubbleSort_with_BestCase(A,N);
    printArray(A,N);
    return 0;
}