#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// CASE - 1
struct Node* deletionAtBeginning(struct Node* head, int data){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// CASE - 2
struct Node* deletionOfNodeInBetween(struct Node* head,int index, int data){
    struct Node *p = head;
    struct Node* q = p->next;
    int i=0;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
    
}

// CASE - 3
struct Node* deletionOfLastnode(struct Node* head){
    struct Node* p = head;
    struct Node* q = p->next;
    while(q!=NULL){
        q = q->next;
    }
    p->next=NULL; 
    free(q);
    return head;
    
    // Alternative

    // while(q->next!=NULL){
    //     q = q->next;
    //     p = p->next;
    // }
    // p->next=NULL; 
    // free(q);
    // return head;

}

// CASE - 4
struct Node* deletionOfNodeWithaGivenValue(struct Node*head, int value){
    struct Node* p = head;
    struct Node* q = p->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
        printf("element is deleted\n");
    }
    else{
        printf("data not found\n");
    }

    return head;
    


}
void linkedlistTraversal(struct Node* ptr){
    while (ptr != NULL){
        printf("element is : %d \n",ptr->data);
        ptr = ptr->next;

    }
}


int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;

    head = (struct Node*) malloc(sizeof(struct Node));
    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head->data = 4;
    head->next = first;

    first->data = 5;
    first->next = second;

    second->data = 7;
    second->next = third;

    third->data = 9;
    third->next = NULL;
    linkedlistTraversal(head);
    printf("AFTER\n");
    // head = deletionAtBeginning(head,4);
    // head = deletionOfNodeInBetween(head, 3, 5);
    // head = deletionOfLastnode(head);
    head = deletionOfNodeWithaGivenValue(head, 0);
    linkedlistTraversal(head);
}

