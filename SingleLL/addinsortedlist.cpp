//adding a node in sorted list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

void print(struct node* head) {
    struct node* temp = head;
    printf("{");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->link;
    }
    printf("}\n");
}

struct node* add(struct node* head, int element) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->link = NULL;

    if (head == NULL || element < head->data) {
        newnode->link = head;
        return newnode;
    }

    struct node* current = head;

    while (current->link != NULL && current->link->data < element) {
        current = current->link;
    }

    newnode->link = current->link;
    current->link = newnode;

    return head;
}

int main() {
    int size;
    printf("Input the size of a sorted linked list: ");
    scanf("%d", &size);

    struct node* head = NULL;

    if (size > 0) {
        struct node* current;
        head = (struct node*)malloc(sizeof(struct node));
        printf("Input the value of element at LL[0]: ");
        scanf("%d", &head->data);
        head->link = NULL;
        current = head;

        for (int i = 1; i < size; i++) {
            int temp;
            struct node* ptr = (struct node*)malloc(sizeof(struct node)); 
            printf("Input the value of element at LL[%d]: ", i);
            scanf("%d", &temp);
            if (temp >= current->data) {
                ptr->data = temp;
                ptr->link = NULL;
                current->link = ptr;
                current = ptr;
            } else {
                printf("The number %d is not part of the linked list (out of order).\n", temp);
                free(ptr);
                i--; 
            }
        }
    }

    printf("The linked list is: ");
    print(head);

    int element;
    printf("Input new element to add to the linked list: ");
    scanf("%d", &element);

    head = add(head, element);

    printf("The linked list after addition is: ");
    print(head);

    return 0;
    
}
