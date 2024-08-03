//
// Created by Aayush Kumar on 20/07/23.
//

#include<stdio.h>

void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void selectionSort(int *a, int n){
    int i,j,indexMin;
    for( i=0; i<n-1; i++){
        indexMin=i;
        for(j=i+1; j<n; j++){
            if(a[indexMin]>a[j]){
                indexMin=j;
            }
        }
        //swapping a[i] and a[indexMin]
        int temp = a[i];
        a[i] = a[indexMin];
        a[indexMin] = temp;
    }
}

int main(){

    //there will be total n-1 passes in selection sort algorithm
    int A[]={8,0,7,1,3};
    int n=5;
    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);

}