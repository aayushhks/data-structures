#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*  next;
    int data;
};

int IsFull(struct Node* top){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;shubhankar r anjanre
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

struct Node* push(struct Node* top, int x){
    struct Node* n = (struct Node*)malloc (sizeof(struct Node));
    if(IsFull(top)){
        printf("stack overflow");
    }
    else{
        n->data = x;
        n->next = top;
        top = n;
        // return top;
    }
    return top;
}

int pop(struct Node** top){
    struct Node* n = *top;
    if(IsEmpty(*top)){
        printf("stack underflow\n");
    }
    else{
        *top=(*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
    return -1;
}

int main(){
    struct Node* top = NULL;
    
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













































