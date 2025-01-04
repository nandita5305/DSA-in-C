//deleting the head

#include <stdio.h>
#include <stdlib.h>

//creating a DoublyLL node
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

//print function
void print(struct node* head){
    struct node* ptr = head;
    printf("The doubly linked list is : {");
    while(ptr != NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("}\n");
}

int main() {
    int size;
    printf("How many nnumbers do you want inside the list ? ");
    scanf("%d", &size);

    struct node* head = NULL;

    if(size>0){
        // Create the head node
        head = (struct node*)malloc(sizeof(struct node));

        if (head == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        head->prev = NULL;

        printf("Enter the number in the list : ");
        scanf("%d", &head->data);

        head->next = NULL;

        struct node* current = head;

        for(int i=1; i<size; i++){
            //creating a node
            struct node* ptr = (struct node*)malloc(sizeof(struct node));

            //allocating the adress of ptr to the previous node for link
            current->next = ptr;

            //inputting data
            int data;
            printf("Enter the number in the list : ");
            scanf("%d", &ptr->data);

            //"current" is stored in the previous pointer of ptr
            ptr->prev = current;
            ptr->next = NULL;

            //updating current
            current = ptr;
        }
    }

    //printing the doubly linked list
    print(head);

    //deleting the head node
    printf("Deleting the head node");

    struct node* newnode = head;
    head = newnode->next;
    head->prev = NULL;
    free(newnode);
    
    print(head);

    return 0;
}
