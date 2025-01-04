#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insertion in a Binary Search Tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // Create and return a new node if tree is empty
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in right subtree
    }

    return root;  // Return the root after insertion
}

// Inorder traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Find the node with the minimum value in the tree (used for deletion)
struct Node* findMin(struct Node* node) {
    struct Node* current = node;

    // Loop to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Deletion of a node from the Binary Search Tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;  // Return if the tree is empty
    }

    // Traverse to the node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);  // Go to left subtree
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);  // Go to right subtree
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: find the inorder successor
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;  // Return the updated root
}

int main() {
    struct Node* root = NULL;
    
    // Inserting nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);  // Output: 20 30 40 50 60 70 80
    printf("\n");

    // Deleting a node with value 20
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);  // Output: 30 40 50 60 70 80
    printf("\n");

    // Deleting a node with value 30
    printf("Deleting 30...\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);  // Output: 40 50 60 70 80
    printf("\n");

    // Deleting a node with value 50
    printf("Deleting 50...\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);  // Output: 40 60 70 80
    printf("\n");

    return 0;
}
