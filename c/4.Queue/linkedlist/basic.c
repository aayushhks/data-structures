#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *next;
    int data;
};

struct Node *rear = NULL;
struct Node *front = NULL;

void display(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int IsFull(struct Node *n){
    if (n == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(){
    if(front== NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int value){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(IsFull(n)){
        printf("Queue is Full %d cannot be added",value);
    }
    else{
        n->data=value;
        n->next = NULL;
        if(front==NULL){
            front = rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue(){
    int a=-1;
    struct Node *ptr = front;
    if(IsEmpty()){
        printf("Queue is empty");
    }
    else{
        front=front->next;
        a = ptr->data;
        free(ptr);
    }
    return a;
}

int main(){
    int size=5;
    for(int i=0; i<size; i++){
        int n;
        printf("enter the element at position %d : ", i+1);
        scanf("%d",&n);
        enqueue(n);
    }
    display(front);
    for(int i=0; i<size; i++){
        printf("dequeue element %d\n",dequeue());
    }
    if(IsEmpty()){
        printf("queue is empty \n");
    }
    return 0;
}