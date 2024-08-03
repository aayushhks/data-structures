//
// Created by Aayush Kumar on 14/08/23.
//

#include<stdio.h>

#include<limits.h>
//vivan #include<string.h>

#include<stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int maximum(int A[], int n){
    int max = INT_MIN;
           // vivan A[]
    for (int i = 0; i < n; i++)
    {
        if (max < A[i]){
            max = A[i];
        }
    }
    return max;

}
void countSort(int * A, int n){
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n);

    // Create the count array
    int* count = (int *) malloc((max+1)*sizeof(int));

    // Initialize the  count array elements to 0
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    // vivan memset(ind_arr, 0, (arr_max+1)*sizeof(int));


    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }


    i =0; // counter for count array
    j =0; // counter for given array A

    while(i<= max){
        if(count[i]>0){
            A[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}



//int greatestNumber(int *A, int n){               ///DUMB ME THIS LONG CODE IS FOR TO FIND MAX ELEMENT
//    int i=0,max;
//    int key=A[i];
//    for(i=1; i<n; i++){
//        if (key>A[i]){                           ///DUMB ME THIS LONG CODE IS FOR TO FIND MAX ELEMENT
//            max=key;
//        }
//        else{
//            key=A[i];
//            max=key;
//        }
//    }
//    return max;
//}                                                ///DUMB ME THIS LONG CODE IS FOR TO FIND MAX ELEMENT

