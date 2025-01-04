//creating a single linked list

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
    current = (struct node*)malloc(sizeof(struct node));

    head->data = 25;
    head->link = NULL;
    current->data =30;
    current->link = NULL;

    head->link = current;

    printf("The value inside head is : %d  and the adress is : %d\n", head->data, head->link);
    printf("The value inside head is : %d  and the adress is : %d\n", head->link->data, head->link->link);

    return 0;
}