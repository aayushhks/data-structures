#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int peek(struct stack*s,int i){
    if((s->top-i+1)<0){
        printf("Invalid Value");
        return -1;
    }
    else{
        return s->arr[s->top-i+1];
    }
}

void push(struct stack *s,int value){
    if(s->top==s->size-1){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}

// int pop(struct stack *s){
//     if(IsEmpty(s)){
//         printf("/~Stack Underflow~/ Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         int value = s->arr[s->top];
//         s->top--;
//         return value;
//     }

// }

int main(){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    printf("Enter the size of you list : ");
    scanf("%d",&(s->size));
    s->top = -1;
    s->arr =(int*)malloc(s->size*sizeof(int));
    int n;
    
    for(int i=1; i<=s->size; i++){
        printf("enter element %d : ",i);
        scanf("%d",&n);
        push(s,n);
    }
    
    for (int j = 1; j <= s->top+1; j++)
    {
        printf("the element at TOP %d is %d \n", j, peek(s,j));
    }
    
}
