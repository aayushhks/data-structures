#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    char *arr;
    int size;
};

int IsFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *s, char value){
    if(IsFull(s)){
        printf("/~Stack Overflow~/ %c ",value);
    }
    else{
        s->top++;
        s->arr[s->top]=value;
    }
}

char pop(struct stack *s){
    if(IsEmpty(s)){
        printf("/~Stack Underflow~/ Cannot pop from the stack\n");
        return -1;
    }
    else{
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int ParanthesisMatch(char *exp){
    struct stack *sp = (struct stack*)malloc (sizeof(struct stack));
    sp->size = 80;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(IsEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    return 0;
}

int  main(){
    char *Exp = "3*(8+9)"; //just for paranthesis valid and invalid expression doesn't matter.

    if(ParanthesisMatch(Exp)){
        printf("the paranthesis are matching");
    }
    else{
        printf("the paranthesis is not matching");
    }
    return 0;
}