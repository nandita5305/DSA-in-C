//creating a new node

#include <stdio.h>
#include <stdlib.h>

//creating node

struct node{
    int data;
    struct node* link;
};

int main(){
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 25;
    head->link = NULL;

    printf("The value inside head is : %d  and the adress is : %d", head->data, head->link);

    return 0;
}