//
// Created by Aayush Kumar on 03/09/23.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int getHeight(struct Node* n){
    if(n==NULL)
        return 0;
    return n->height;
}

struct Node* createNode(int data){
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int getBalanceFactor(struct Node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct Node* rightRotate(struct Node* y){
    struct Node* x= y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct Node *insertNode(struct Node* node, int key){
    if(node==NULL)
        return createNode(key);

    if(key < node->data)
        node->left = insertNode(node->left,key);
    else if(key > node->data)
        node->right = insertNode(node->right,key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // left-left case
    if (bf>1 && key < node->left->data) {
        return rightRotate(node);
    }
    // right-right case
    if (bf<-1 && key > node->right->data) {
        return leftRotate(node);
    }
    // left right case
    if (bf>1 && key > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case
    if (bf<-1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct Node* root = NULL;
    root = insertNode(root,1);
    root = insertNode(root,2);
    root = insertNode(root,4);
    root = insertNode(root,5);
    root = insertNode(root,6);
    root = insertNode(root,3);

    preOrder(root);
    return 0;
}