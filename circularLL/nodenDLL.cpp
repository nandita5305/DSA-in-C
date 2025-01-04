//creating a circular linked list using a doubly linked list

#include <stdio.h>
#include <stdlib.h>

//defining structure
struct node{
    struct node* prev;
    int data;
    struct node* next;    
};

//print function
void print(struct node* head, int size){
    struct node* ptr = head;
    printf("The circular linked list is : {");
    for(int i=0; i<=size; i++){
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("}\n");
}

int main(){
    int size;
    printf("Enter the number of element in the list : ");
    scanf("%d", &size);


    if(size>0){
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input value : ");
        scanf("%d", &head->data);

        struct node* ptr, *current = head;

        for(int i=0; i<size-1; i++){
            ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the value : ");
            scanf("%d", &ptr->data);

            current->next = ptr;
            ptr->prev = current;

            current = ptr;
        }

        current->next = head;
        head->prev = current;

        print(head, size);
    }

    return 0;
}