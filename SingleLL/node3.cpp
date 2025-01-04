//creating third node for the linked list

#include <stdio.h>
#include <stdlib.h>

//creating node

struct node{
    int data;
    struct node* link;
};

int main(){
    struct node* head, *current;
    head = (struct node*)malloc(sizeof(struct node));    
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for current node
    current = (struct node*)malloc(sizeof(struct node));
    if (current == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //Initializing head node
    head->data = 25;
    head->link = NULL;

    //Initialising current node
    current->data =30;
    current->link = NULL;

    //Link head to current node
    head->link = current;

    //ALlocate memory for the third node
    current->link = (struct node*)malloc(sizeof(struct node));
    if (current->link == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    current->link->data =50;
    current->link->link = NULL;
    head->link->link=current;

    printf("The value inside head is : %d  and the adress is : %p\n", head->data, head->link);
    printf("The value inside head is : %d  and the adress is : %p\n", current->data, current->link);
    printf("The value inside head is : %d  and the adress is : %p\n", current->link->data, current->link->link);

    // Free allocated memory
    free(current->link);
    free(current);
    free(head);

    return 0;
}