//
// Created by Aayush Kumar on 25/08/23.
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

void *inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node* searchingInBST(struct node* root, int element){
    if(root==NULL){
        return root;
    }
    if ((root->data)== element){
        return root;
    }
    else if ((root->data)>element){
        return searchingInBST(root->left,element);
    }
    else{
        return searchingInBST(root->right,element);
    }
}

int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left  = p3;
    p1->right = p4;

    inOrder(p);
    struct node *n = searchingInBST(p,6);
    if(n!=NULL){
        printf("\nelement found");
    }
    else{
        printf("\nelement not found");
    }
    return 0;
}