#include<stdio.h>
#include<stdlib.h>


struct queue {
    int rear , front;
    int size ;
    int *arr;
};

void display(struct queue *q){
    for(int i=0 ; i <= q->rear ; i++){
//        printf("element at position %d is : %d\n",i,q->arr[i]);
        printf("%d \t",q->arr[i]);
    }
    printf("\n");
}

int IsFull(struct queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct queue *q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q, int value){

    if (IsFull(q)){
        printf("Queue Overflow %d cannot be added\n",value);
    }
    else{
        q->rear++;
        q->arr[q->rear] = value;
    }
}

 int dequeue(struct queue *q){
    int a = -1;
     if (IsEmpty(q)){
         printf("Queue Underflow");
     }
     else {
         q->front++;
         a = q->arr[q->front];
     }
     return a;
 }
int main(){
    struct queue *Q = (struct queue*)malloc(sizeof(struct queue));
    Q->size = 3;
    Q->front = Q->rear = -1;
    Q->arr = (int *)malloc(Q->size * sizeof(int));
    int n;
    for(int i = 0; i<Q->size; i++) {
        printf("enter the number %d : ", i+1);
        scanf("%d", &n);
        enqueue(Q, n);
    }
    display(Q);
    for(int i=0 ; i<Q->size ; i++){
        printf("dequeue element %d \n",dequeue(Q));
    }
    display(Q);
    enqueue(Q,23);     // her we tried adding more elements but it was full thats why we need circular queue.
    enqueue(Q,56);
    enqueue(Q,78);

    if(IsEmpty(Q)) {
        printf("Queue is Empty\n");
    }
    if(IsFull(Q)) {
        printf("Queue is Full\n");
    }
    return 0;

}