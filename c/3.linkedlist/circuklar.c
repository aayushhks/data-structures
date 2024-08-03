#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void TraversalCircular(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=head);

}

struct Node* insertionAtBeginning(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p = head->next;
    ptr->data = data;

    while(p->next!=head){
        p = p->next;

    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}

int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;

    head =(struct Node*)malloc(sizeof(struct Node));
    first =(struct Node*)malloc(sizeof(struct Node));
    second =(struct Node*)malloc(sizeof(struct Node));
    third =(struct Node*)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = first;

    first->data = 8;
    first->next = second;

    second->data = 0;
    second->next = third;

    third->data = 6;
    third->next = head;

    TraversalCircular(head);
    insertionAtBeginning(head,67);
    TraversalCircular(head);

}