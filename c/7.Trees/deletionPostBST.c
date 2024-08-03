//
// Created by Aayush Kumar on 02/09/23.
//

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node *inOrderPost(struct node* root){
    root = root->right;
    while (root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *deletionNode(struct node *root, int value){

    struct node* iPost;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deletionNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deletionNode(root->right,value);
    }

        //deletion strategy when the node is found
    else{
        iPost = inOrderPost(root);
        root->data = iPost->data;
        root->right = deletionNode(root->right, iPost->data);
    }
    return root;
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

//        8
//       / \
//      3   10
//     / \    \
//    1   6    14
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
    inOrder(p);
    printf("\n");
    deletionNode(p,8);
    inOrder(p);
    printf("\n");
    deletionNode(p,7);
    inOrder(p);
    printf("\n");
    deletionNode(p,5);
    inOrder(p);
    printf("\n");
    deletionNode(p,3);
    inOrder(p);
    printf("\n");
    deletionNode(p,4);
    inOrder(p);
    printf("\n");
    deletionNode(p,13);
    inOrder(p);
    printf("\n");
    deletionNode(p,13);
    inOrder(p);
    printf("\n");
    deletionNode(p,6);
    inOrder(p);
    printf("\n");
    deletionNode(p,10);


    printf("\n|New root : %d|\n",p->data);
    return 0;
}


