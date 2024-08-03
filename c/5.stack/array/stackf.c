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

int IsEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){

    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pushing a element manually
    s->top++;
    s->arr[s->top]=7;
    s->top++;
    s->arr[s->top]=3;
    s->top++;
    s->arr[s->top]=4;

    if(IsEmpty(s)){
        printf("stack is Empty \n");
    }
    else{
        printf("stack is not Empty \n");
    }
    if(IsFull(s)){
        printf("stack is Full \n");
    }
    else{
        printf("stack is not Full \n");
    }
    return 0;

}