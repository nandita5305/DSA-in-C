//creating a single node in a circular linked list using single linked list

#include <stdio.h>
#include <stdlib.h>

//defining structure
struct node {
    int data;
    struct node* link;
};

int main(){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    printf("Adress of ptr is : %d\n", ptr);
    printf("Input value of node : ");
    scanf("%d", &ptr->data);
    ptr->link = ptr;

    //printing to check the back connection of the list
    printf("THe head node is : { %d %d }", ptr->data, ptr->link);

    return 0;
}