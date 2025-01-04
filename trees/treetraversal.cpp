#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left, *right;
};

struct node* createnode(int data){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL;
    newnode->data = data;
    return newnode;
};

void preorder(struct node* node){
    if(node==NULL){
        return;
    }
    printf(" %d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct node* node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    printf(" %d ", node->data);
    inorder(node->right);
}

void postorder(struct node* node){
    if(node==NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf(" %d ", node->data);
}

int main() {
    // Create an example binary tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    struct node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    printf("Preorder traversal: ");
    preorder(root);  // Output: 1 2 4 5 3

    printf("\nInorder traversal: ");
    inorder(root);  // Output: 4 2 5 1 3

    printf("\nPostorder traversal: ");
    postorder(root);

    return 0;
}