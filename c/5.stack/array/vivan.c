#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    char *arr;
    int top;
};

int IsFull(struct stack *s){
    return(s->top==s->size-1);
}

int IsEmpty(struct stack *s){
    return (s->top==-1);
}

void push(struct stack *s, char value){
    if(IsFull(s)){
        printf("/~Stack Overflow~/ %d ",value);
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
int match(char a, char b ) {
    return (a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']');
}

int MultipleParanthesisMatching(char *exp){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack)) ;
    sp->size = 1000;
    sp->top = -1;
    char popped_ch;

    sp->arr = (char*)malloc(sp->size*sizeof(char));
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if (IsEmpty(sp)) {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch,exp[i])) {
                return 0;
            }
        }
    }
    if (IsEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char *Exp = "4*{8}}";
    if(MultipleParanthesisMatching(Exp)){
        printf("the parenthesis is balanced");
    }
    else{
        printf("the parenthesis is not balanced");
    }
}

