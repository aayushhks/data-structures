#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int *arr;
    int top;
};

int IsFull(struct stack * ptr){
    printf("size - %d , top - %d\n", ptr->size, ptr->top);
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }

}

void push(int value){

}