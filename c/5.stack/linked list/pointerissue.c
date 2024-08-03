#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*  next;
    int data;
};

struct Node* top = NULL;

int IsFull(struct Node* top){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }
    else{return 0;}
}

int IsEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void linkedlistTraversal(struct Node* ptr){
    while (ptr != NULL){
        printf("element is : %d \n",ptr->data);
        ptr = ptr->next;

    }
}

int paranthesisMatch(char *exp){
    struct stack *s;
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(s,exp[i]);
        }
        else if(exp[i]==')'){
            if(IsEmpty(s)){
                return 0;
            }
        pop(s);
        }
    }
    return top;
}

int pop(struct Node** tp){
    struct Node* n = *tp;
    if(IsEmpty(*tp)){
        printf("stack underflow\n");
    }
    else{
        *tp=(*tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
    return -1;

}

int main(){
    
    top = push(top,5);
    top = push(top,6);
    top = push(top,7);
    top = push(top,8);
    
    linkedlistTraversal(top);
    printf("\n");
    int ele = pop(&top);

    printf("element deleted is %d\n",ele);
    printf("\n");
    linkedlistTraversal(top);

    return 0;
}













































