//
// Created by Aayush Kumar on 18/08/23.
//

#include<stdio.h>

void Search(int A[], int n,int target){
    int k=0;
    for(int i=0; i<n; i++) {
        if (target == A[i]) {
            k=i;
            printf("%d\n",k);
        }
    }
}

int linearSearch(int A[], int n , int target){
    if()
}
int main(){
     int A[] = {2,4,2,6,9};
     int n = 5;
     int target =2;
     linearSearch(A,n,target);
     return 0;
}