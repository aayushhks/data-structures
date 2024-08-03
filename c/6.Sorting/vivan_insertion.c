#include<stdio.h>

void insertionSort(int array[], int arr_len) {
    for (int i = 1; i < arr_len; i++) {
        int key=array[i];
        int j = i - 1;
        while(j >= 0 && array[j]>key ) {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}


int main() {
    int arr[] = {12, 0, 20, 17, 69, 4};
    int arr_len = 6;

    insertionSort(arr, arr_len);
    for (int i = 0; i <= arr_len - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
