//
// Created by Aayush Kumar on 20/07/23.
//
#include <stdio.h>

int swaps = 0;
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
            swaps++;
        }
        while (A[j] > pivot)
        {
            j--;
            swaps++;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            swaps++;
        }
    }while (i < j);
    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    swaps++;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}
int main()
{
//    int A[]={10,9,8,7,6,5,4,3,2,1};
    int A[]={4,5,1,2};
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    int n = 4;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    printf("No. of swaps are : %d",swaps);
    return 0;
}
