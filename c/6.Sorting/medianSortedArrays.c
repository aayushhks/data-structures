//
// Created by Aayush Kumar on 20/09/23.
//
#include<stdio.h>
#include<stdlib.h>
int *merge(int *arr1, int l1, int *arr2, int l2, int *arr3) {

    int i = 0, j = 0, k = 0;
    while (i < l1 && j < l2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < l1) {
        arr3[k++] = arr1[i++];
    }
    while (j < l2) {
        arr3[k++] = arr2[j++];
    }
    return arr3;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *nums, numsSize;
    double returnValue;
    numsSize = nums1Size + nums2Size;
    nums = malloc(numsSize * sizeof(int));
    nums = merge(nums1, nums1Size, nums2, nums2Size, nums);
    if (numsSize & 1) {
        returnValue = (double) nums[numsSize/2];
    } else {
        returnValue = (double) (nums[numsSize/2-1] + nums[numsSize/2]) / 2.0;
    }
    free(nums);
    return returnValue;
}

int main(){
    int nums1[]={1,3};
    int nums2[]= {2};
    int nums1Size = 2;
    int nums2Size = 1;
    findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    return 0;
}
