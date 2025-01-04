//reversing the whole list

#include <stdio.h>
#include <stdlib.h>

//creating node

struct node{
    int data;
    struct node* link;
};

struct node* reverselist(struct node* head){
    struct node* ptr = head, *prev = NULL, *next = NULL;

    while(ptr != NULL){
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }

    head = prev;
    return head;
}

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

            //checking if tthe memory is full
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

    int n, position;
    printf("Do you want to reverse the linked list? 1/0 ");
    scanf("%d", &n);

    if(n==1){
        head = reverselist(head);
        print(head);
    }
    
    return 0;
}