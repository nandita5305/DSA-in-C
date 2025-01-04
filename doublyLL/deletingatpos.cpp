//adding a new node in the LL

#include <stdio.h>
#include <stdlib.h>

//creating a DoublyLL node
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

//deleting at a position
struct node* deletepos(struct node* head, int pos){
    struct node* ptr = head;

    if(pos==0){
        head = head->next;
        head->prev = NULL;
        free(ptr);
        return head;
    }

    for(int i=0; i<pos; i++){
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return head;
}

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
    printf("How many numbers do you want inside the list ? ");
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

        printf("Enter the element at doublyLL[0] : ");
        scanf("%d", &head->data);

        head->next = NULL;

        struct node* current = head;

        for(int i=1; i<size; i++){
            //creating a node
            struct node* ptr = (struct node*)malloc(sizeof(struct node));

            //allocating the adress of ptr to the previous node for link
            current->next = ptr;

            //inputting data
            printf("Enter the element at doublyLL[%d] : ", i);
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
    int pos;
    printf("Input the position to be deleted : ");
    scanf("%d", &pos);

    if(pos>size){
        printf("Out of range");
    }
    
    else if(pos==size){
        struct node* ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        print(head);
    }

    else{
        head = deletepos(head, pos);
        print(head);
    }

    return 0;
}
