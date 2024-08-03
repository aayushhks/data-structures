#include<stdio.h>

//Traversal
void Display(int arr[],int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}




//Insertion
int IndexInsertion(int arr[], int size, int element, int index, int capacity){
    if(size>=capacity){
        return -1;
    }
    for(int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

//Deletion
void IndexDeletion(int arr[], int size, int index, int capacity){
    if (index>capacity){
        printf("invalid");
    }
    for(int i=index; i<=size-1; i++){
        arr[i]=arr[i+1];
    }
}

//Main
int main(){
    int arr[100]={1, 2, 3, 4, 5};
    int size = 5, element, index;
    // printf("enter the element you want to insert  : ");
    // scanf("%d", &element);
    printf("enter the index you want to delete at : ");
    scanf("%d", &index);
    printf("Before\n");
    Display(arr,size);
    // IndexInsertion(arr, size, element, index, 100);
    // size+=1;
    IndexDeletion(arr, size, index, 100);
    size-=1;
    printf("after\n");
    Display(arr,size);
    

    return 0;

}