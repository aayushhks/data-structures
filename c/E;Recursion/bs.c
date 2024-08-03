//
// Created by Aayush Kumar on 20/08/23.
//

#include<stdio.h>

int binary(int arr[],int element, int size){
    int low, mid, high;
    low = 0;
    high = size-1;
    // n searching starts
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid + 1;       // you can take low = mid also that will also be sufficent but more smart way is this-> (+1)
        }                       // but more smart way is this-> (+1)
        else{
            high = mid - 1;
        }
    }
    return -1;
    // searching ends
}

int main(){
    int n;
    printf("enter the size : ");
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++){
        printf("enter the element %d ",i);
        scanf("%d", &A[i]);
    }
    int target;
    printf("enter the target");
    scanf("%d",&target);
    int searchIndex = binary(A, target , n);
    printf("%d",searchIndex);
    return -1;
}