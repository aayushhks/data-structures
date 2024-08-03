#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    char *arr;
    int size;
};

char stackTop(struct stack *s){
    return s->arr[s->top];
}

int IsFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct stack *s){
    if (s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *s, char value){
    if(IsFull(s)){
        printf("Stack Overflow %d",value);
    }
    else{
        s->top++;
        s->arr[s->top]=value;
    }
}

char pop(struct stack *s){
    if(IsEmpty(s)){
        printf("Stack Underflow");
        return -1;
    }
    else{
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int IsOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 1;
    else
        return 0;
}

int Precedence(char ch){
    if(ch=='*' || ch=='/')
        return 3;
    else if(ch=='+' || ch=='-')
        return 2;
    else
        return 0;
}

char *InfixToPostfix(char *infix){
    struct stack *sp = (struct stack*)malloc (sizeof(struct stack));
    sp->size = 200;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size*sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1)*sizeof(char));

    int i = 0; int j = 0;

    while(infix[i]!='\0'){
        if (!IsOperator(infix[i])){
            postfix[j]=infix[i];
            j++; i++;
        }
        else{
            if(Precedence(infix[i]) > Precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!IsEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char * infix = "m-q-r/a";
    printf("stack after postfix conversion is : %s",InfixToPostfix(infix));

    return 0;
}
