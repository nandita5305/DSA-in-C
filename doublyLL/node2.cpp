//adding a new node in the LL
#include <stdio.h>
#include <stdlib.h>

//creating a DoublyLL node
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

//main
int main(){

    //creating the head node
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 5;
    head->next =NULL;

    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = 5;
    ptr->next =NULL;

    //printing the head node
    printf("{ %d, %d }", (head->data), (ptr->data));

    return 0;
}