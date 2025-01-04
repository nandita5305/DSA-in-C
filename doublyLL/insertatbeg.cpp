//adding nodes at the begining of the list

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

        struct node* ptr, *current = head;

        for(int i=1; i<size; i++){
            //creating a node
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->prev = NULL;

            //inputting data
            head->prev = ptr;

            //fetching data
            int data;
            printf("Enter the number in the list : ");
            scanf("%d", &ptr->data);

            ptr->next = head;

            //updating head
            head = ptr;
        }
    }

    printf("Reversed linked list : ");
    print(head);

    return 0;
}
