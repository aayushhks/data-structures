#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* next;
    int data;
};

// CASE - 1
struct Node* insertAtBeginning(struct Node *head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// CASE - 2
struct Node* insertAtIndex(struct Node *head, int data, int index){    // It will not work for 0 index because it is
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));      // functiuon for between
    struct Node* p = head;
    int i=0;
    while (i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}

// CASE - 3
struct Node* insertAtEnd(struct Node* head,int data){
    struct Node *ptr= (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
}


// CASE - 4
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data){
    struct Node* ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next=prevNode->next;
    prevNode->next = ptr;
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

    
    head = (struct Node*)malloc (sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    

    head->data = 3;
    head->next = first;

    first->data = 4;
    first->next = second;

    second->data= 5;
    second->next = NULL;

    linkedlistTraversal(head);
    printf("After\n");
    // head = insertAtBeginning(head,78);
    // head = insertAtIndex(head,8,2);
    // insertAtEnd(head,56);
    head = insertAfterNode(head,head, 45);
    
    linkedlistTraversal(head);
    
}