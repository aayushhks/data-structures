#include<stdio.h>
#include<stdlib.h>

struct stack{
    int *arr;
    int size;
    int top;
};

int stackBottom(struct stack *s){
    return s->arr[0];
}

int stackTop(struct stack* s){
    return s->arr[s->top]; 
}

void push(struct stack *s, int value){

    if (s->top==s->size-1){
        printf("stack overflow");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
    
}

int main(){
    int x;
    struct stack *s = (struct stack*)malloc (sizeof(struct stack));
    printf("enter the size of stack : ");
    scanf("%d",&s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));

    for (int i = 1; i <= s->size; i++){
        printf("enter the element %d : ",i);
        scanf("%d",&x);
        push(s,x);
    }

    for(int i=0; i<=s->top; i++){
        printf("element at %d : is %d\n",i,s->arr[i]);
    }

    printf("Bottom Element : %d \n",stackBottom(s));
    printf("Top Element : %d \n",stackTop(s));
}