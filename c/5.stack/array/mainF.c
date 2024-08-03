#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int *arr;
    int top;
};

int IsFull(struct stack * ptr){
    // printf("\tBefore\nsize = %d , top = %d\n", ptr->size, ptr->top);
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct stack * ptr){
    // printf("\tBefore\nsize = %d , top = %d\n", ptr->size, ptr->top);
    if(ptr->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct stack *ptr, int value){
    
    if(IsFull(ptr)){
        printf("/~Stack Overflow~/ Cannot push %d in the stack \n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}
int pop(struct stack *s){

    if(IsEmpty(s)){
        printf("/~Stack Underflow~/ Cannot pop from the stack\n");
        return -1;
   } 
    else{
        int value = s->arr[s->top];
        s->top--;
        return value;
    }

}

void display(struct stack *s){
    for(int i=0 ; i <= s->top ; i++){
        printf("element at position %d is : %d\n",i,s->arr[i]);
    }
}

int main(){
    int x;
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    printf("how many numbers you want to push : ");
    scanf("%d",&s->size);
    // s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
   
    //pushing data manually
    // s->top++;
    // s->arr[s->top]=3;
    // s->top++;
    // s->arr[s->top]=6;
    // s->top++;
    // s->arr[s->top]=3;
    // s->top++;
    // s->arr[s->top]=4;
    
    for(int i=0; i<s->size; i++){
        printf("Enter value number %d: ", i+1);
        scanf("%d", &x);
        push(s, x);
    }
    
    int i;
    for(i=0; i<s->size-1; i++){
       printf("%d, ",*(s->arr+i));
    }
    printf("%d",*(s->arr+i));
    printf("\n");
    
    display(s);
    pop(s);
    printf("after\n");
    display(s);
    return 0;

}