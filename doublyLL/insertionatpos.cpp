//adding a node at a position

#include <stdio.h>
#include <stdlib.h>

//creating a DoublyLL node
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

//function to insert a number at a particular position
struct node* addatpos(struct node* head, int data, int pos, int size){
    size++;
    struct node* ptr = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(pos == 0){
        head->prev = newnode;
        newnode->prev = NULL;
        newnode->data = data;
        newnode->next = head;

        head = newnode;

        return head;
    }

    if(pos==size){
        while(ptr->next!=head){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->data = data;
        newnode->next = head;

        return head;
    }

    for(int i=1; i<pos; i++){
        ptr = ptr->next;
    }

    newnode->next = ptr;
    newnode->data = data;
    newnode->prev = ptr->prev;
    ptr->prev->next = newnode;
    ptr->prev = newnode;

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

        printf("Enter the number in the doublyLL[0] : ");
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
            printf("Enter the number in the doublyLL[%d] : ", i);
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

    int data, pos;
    printf("Enter the number to be added in the list : ");
    scanf("%d", &data);
    printf("Enter the position : ");
    scanf("%d", &pos);
    if(pos<=size){
        head = addatpos(head, data, pos, size);
        print(head);
    }
    else{
        printf("Out of range");
    }

    return 0;
}
