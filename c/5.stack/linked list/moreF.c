#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int IsFull(struct Node* top){
    struct Node* p =(struct Node*)malloc(sizeof(struct Node));
    if (p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node* top, int x){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(IsFull(top)){
        printf("stack overflow\n");
    }
    else{
        n->data = x;
        n->next = top;
        top = n;
    }
    return top;

}

void traversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("element is: %d\n", ptr->data);
        ptr=ptr->next;
    }
}

int peek(int pos){
    struct Node* n = top;
    for(int i=0; ( i<pos-1 && n!=NULL ); i++){
        n = n->next;
    }
    if(n!=NULL){
        return n->data;
    }
    else{
        return -1;
    }
}

int stackTop(struct Node* top){
    if (IsEmpty(top)){
        return -1;
    }
    else{
        return top->data;
    }
    
}

int stackBottom(struct Node* top){
    struct Node* ptr = top;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }  
    return ptr->data;
    
}

int main(){
    top = push(top,5);
    top = push(top,7);
    top = push(top,9);
    traversal(top);
    printf("peek position of an element is : %d\n",peek(2));
    printf("TOP element is : %d\n",stackTop(top));
    printf("Bottom element is : %d\n",stackBottom(top));

    return 0;
}