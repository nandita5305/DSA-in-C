//creating a single node forr a doubly linked list

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

    //printing the head node
    printf("{ %d }", (head->data));

    return 0;
}