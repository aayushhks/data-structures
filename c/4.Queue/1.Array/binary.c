#include<stdio.h>

// binary search for sorted array
int binary(int arr[],int element, int size){ 
    int low, mid, high;
    low = 0;
    high = size-1;
    // nsearching starts
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
    int arr[]={1,2,3,4,5,6};
    int element, size = sizeof(arr)/sizeof(int);
    printf("element you want to find : ");
    scanf("%d",&element);
//    int arr[100];
//    int element,size = sizeof(arr)/sizeof(int);
//    printf("enter the elements : ");
//    for(int i=0; i<size; i++){
//        scanf("%d",&arr);
//    }
    int searchindex = binary(arr, element, size);
    printf("the element %d was found at index %d \n",element,searchindex);
    return 0;

}