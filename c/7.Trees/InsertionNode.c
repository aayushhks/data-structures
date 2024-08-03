//
// Created by Aayush Kumar on 26/08/23.
//
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct Node *createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node*)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; //Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return  n; // Finally returning the created node
}

void *InOrder(struct node* root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

void *InsertionNode(struct node* root, int key){
    struct node* prev = NULL;
    while(root!=NULL) {
        prev = root;
        if (key == root->data) {
            printf("\ncannot insert %d, Already in BST.",key);
            return 0;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    struct node *newNode = createNode(key);
    if(key<prev->data){
        prev->left=newNode;
    }
    else{
        prev->right=newNode;
    }
}

int main(){
    struct node *p = createNode(8);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(10);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(6);
    struct node *p5 = createNode(14);
    struct node *p6 = createNode(4);
    struct node *p7 = createNode(7);
    struct node *p8 = createNode(13);

//         8
//       /   \
//      3      10
//     / \     /  \
//    1   6   -9-  14
//       / \   /
//      4   7 13
    p->left = p1;
    p->right = p2;
    p1->left  = p3;
    p1->right = p4;
    p2->right = p5;
    p4->left  = p6;
    p4->right = p7;
    p5->left = p8;
    InOrder(p);
    InsertionNode(p,13);
    printf("\n");
    InOrder(p);
    return 0;
}
