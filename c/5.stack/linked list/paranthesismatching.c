#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node*next;
};

struct Node* top = NULL;

int IsFull(struct Node* top){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void linkedlistTraversal(struct Node* ptr){
    while (ptr != NULL){
        printf("element is : %c \n",ptr->data);
        ptr = ptr->next;

    }
}

int pat(struct Node* top, char exp){
    struct Node* ptr = (struct Node*)malloc (sizeof(struct Node));
    char y  = exp;
    if(IsFull(top)){
        printf("stack underflow");
    }
    else{
        ptr->data = y;
        top->next = ptr;
        top = ptr;
    }
    return top;
}

// int popP(){

// }

int main(){
    char exp;
    printf("Enter the expression : ");
    scanf("%c",&exp);
    pushP(top,exp);
    linkedlistTraversal(top);
    return -1;
}