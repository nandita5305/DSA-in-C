//creating the last node as the head node

#include <stdio.h>
#include <stdlib.h>


//creating node

struct node{
    int data;
    struct node* link;
};


//function to create the last node as the head node

struct node* changenode(struct node* head){
    struct node* ptr, *current = NULL;
    ptr = head;
    while(ptr->link != NULL){
        current = ptr; ///this will go upto the second last node in the list
        ptr = ptr->link;
    }
    ptr->link = head;
    current->link = NULL;
    head = ptr;

    return head;
}


//print node

void print(struct node* head){
    if(head == NULL){
        printf("The linked list is empty\n");
    }
    struct node* ptr = head;
    printf("The linked list is : {");
    while(ptr != NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("}\n");
}


int main(){
    int size;
    printf("Enter the number of elements in the linked list : ");
    scanf("%d", &size);
    
    struct node *head, *current, *ptr;
    
    //creating head
    head = (struct node*)malloc(sizeof(struct node));

    if (head == NULL) {

        //checking if the memory is full
        printf("Memory allocation failed\n");
        return 1;
    }

    else if(size>0){
        printf("Enter the element at 1 position of the linked list : ");
        scanf("%d", &(head->data));
        head->link=NULL;

        //storing the adress of head into another pointer so the the value of the head does not change
        ptr = head;

    }

    else{
        printf("No elements in the linked list");
        return 1;
    }
    
    //entering elements in the liked list from 2nd position
    for(int i = 1; i<size; i++){
        current = (struct node*)malloc(sizeof(struct node));

        if (current == NULL) {

            //checking if the memory is full
            printf("Memory allocation failed\n");
            return 1;
        }

        else{
            printf("Enter the element at %d position of the linked list : ", i+1);
            scanf("%d", &(current->data));
            current->link=NULL;

            //using the ptr to access the previous node until the end of loop
            ptr->link = current;

            //updating the value of ptr
            ptr = current;
        }
    }

    print(head);

    if(size>1){
        printf("Putting the last node as the front node : ");
        head = changenode(head);
        print(head);
    }
    
    return 0;
}