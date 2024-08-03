#include<stdio.h>
#include<stdlib.h>


struct circularqueue {
    int rear , front;
    int size ;
    int *arr;
};

void display(struct circularqueue *q){
    for(int i=0 ; i <= q->rear ; i++){
//        printf("element at position %d is : %d\n",i,q->arr[i]);
        printf("%d \t",q->arr[i]);
    }
    printf("\n");
}

int IsFull(struct circularqueue *q){
    if((q->rear+1)%q->size==q->front){   // checking for full in CIRCULAR QUEUE
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct circularqueue *q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct circularqueue *q, int value){

    if (IsFull(q)){
        printf("Queue Full %d cannot be added : \n",value);
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct circularqueue *q){
    int a = -1;
    if (IsEmpty(q)){
        printf("Queue is empty\n");
    }
    else {
        q->front = (q->front+1)%q->size;
        a = q->arr[q->front];
    }
    return a;
}
int main(){
    struct circularqueue *Q = (struct circularqueue*)malloc(sizeof(struct circularqueue));
    Q->size = 4;
    Q->front = Q->rear = 0;
    Q->arr = (int *)malloc(Q->size * sizeof(int));
    int n;
    for(int i = 1; i<Q->size; i++) {
        printf("enter the number %d : ", i);
        scanf("%d", &n);
        enqueue(Q, n);
    }

    display(Q);
    for(int i=1 ; i<Q->size ; i++){
        printf("dequeue element %d \n",dequeue(Q));
    }

    int z = Q->size-1;                          // makes program more readable.
    printf("Enqueue again, %d places are empty\n",z);

    for(int i = 1; i<Q->size; i++) {
        printf("enter the number %d : ", i);
        scanf("%d", &n);
        enqueue(Q, n);
    }

    display(Q);

    // for(int i=1 ; i<Q->size ; i++){
    //     printf("dequeue element %d \n",dequeue(Q));
    // }

    if(IsEmpty(Q)){
        printf("Queue is Empty");
    }
    if(IsFull(Q)){
        printf("Queue if Full");
    }
    return 0;

}