//
// Created by Aayush Kumar on 18/08/23.
//

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node* right
};

struct Node *createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node*)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; //Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return  n; // Finally returning the created node
}


int main(){
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(2);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(5);
    p->left=p1;
    p->right=p2;



    //method down is one by one approach

    // Constructing the root node
//    struct node *p;
//    p = (struct node*)malloc(sizeof(struct node));
//    p->data=1;
//    p->left=NULL;
//    p->right=NULL;
//
// Constructing the second node
//    struct node *p1;
//    p->data=5;
//    p->left=NULL;
//    p->right=NULL;
//
// Constructing the third node
//    struct node *p2;
//    p->data=9;
//    p->left=NULL;
//    p->right=NULL;
//
//    p->left=p1;
//    p->right=p2;

    return 0;
}
