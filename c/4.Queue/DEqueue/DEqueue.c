#include<stdio.h>
#include<stdlib.h>


struct DEqueue {
    int rear , front;
    int size ;
    int *arr;
};

void display(struct DEqueue *q){
    for(int i=0 ; i <= q->rear ; i++){
//        printf("element at position %d is : %d\n",i,q->arr[i]);
        printf("%d \t",q->arr[i]);
    }
    printf("\n");
}

int IsFull(struct DEqueue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct DEqueue *q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueueR(struct DEqueue *q, int value){

    if (IsFull(q)){
        printf("Queue Overflow %d cannot be added\n",value);
    }
    else{
        q->rear++;
        q->arr[q->rear] = value;
        printf("\nsuccessfully element added from Rear of queue\n");
    }
}

// Enqueue from Front
void enqueueF(struct DEqueue *q, int value){

    if (IsFull(q) || q->front==-1){
        printf("Queue Overflow %d cannot be added\n",value);
    }
    else{
        q->arr[q->front] = value;
        q->front++;
        printf("\nsuccessfully element added from front of queue\n");
    }
}

int dequeueF(struct DEqueue *q){
    int a = -1;
    if (IsEmpty(q)){
        printf("Queue Underflow");
    }
    else {
        q->front++;
        a = q->arr[q->front];
        q->front++;
        printf("\nelement successfully dequeued from front\n");
    }
    return a;
}

// Dequeue from Rear
int dequeueR(struct DEqueue *q){
    int a = -1;
    if (IsEmpty(q)){
        printf("Queue Underflow");
    }
    else {
        q->rear--;
        a = q->arr[q->rear];
        printf("\nelement successfully dequeued from rear\n");
    }
    return a;
}

int main(){
    struct DEqueue *Q = (struct DEqueue*)malloc(sizeof(struct DEqueue));
    Q->size = 4;
    Q->front = Q->rear = -1;
    Q->arr = (int *)malloc(Q->size * sizeof(int));
//    int n;
//    for(int i = 0; i<Q->size; i++) {
//        printf("enter the number %d : ", i+1);
//        scanf("%d", &n);
//        enqueueR(Q, n);
//    }
//    display(Q);
//    for(int i=0 ; i<Q->size ; i++){
//        printf("dequeue element %d \n",dequeueF(Q));
//    }
    enqueueR(Q,23);     // here we tried adding more elements but it was full thats why we need circular queue.
    enqueueR(Q,56);
    enqueueR(Q,78);
    display(Q);
    dequeueF(Q);
    dequeueF(Q);
    display(Q);
    enqueueF(Q,58);
    enqueueF(Q,89);
    display(Q);


    if(IsEmpty(Q)) {
        printf("Queue is Empty\n");
    }
    if(IsFull(Q)) {
        printf("Queue is Full\n");
    }
    return 0;

}