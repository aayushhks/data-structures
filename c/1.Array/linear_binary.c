// #include<stdio.h>

// void linear(int arr[],int size, int element){
//     for(int i=0; i<=size-1; i++){     //i<size both are correct
//         if (arr[i]==element){
//             printf("element found at index : %d\n",i);
//             break;
//         }
//         else{
//             printf("element not found\n");
//             break;
//         }
//     }
    

// }
// int main(){
//     int arr[]={1,34,56,78,90};
//     int element,size=sizeof(arr)/sizeof(int);
//     printf("enter the element you want to search : ");
//     scanf("%d",&element);
//     linear(arr, 100, element);
//     return 0;
// }


//

#include<stdio.h>

int linear(int arr[],int size, int element){
    for(int i=0; i<=size-1; i++){     //i<size both are correct
        if (arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,34,56,78,90};
    int element,size=sizeof(arr)/sizeof(int);
    printf("enter the element you want to search : ");
    scanf("%d",&element);
    int searchindex = linear(arr, 100, element);
    printf("element %d was found at index %d \n", element, searchindex);
    return 0;
}