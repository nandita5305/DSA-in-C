//creating n nodes in a linked list

#include <stdio.h>
#include <stdlib.h>

//creating node

struct node{
    int data;
    struct node* link;
};


int main(){
    int n;
    printf("Enter the number of elements in the linked list : ");
    scanf("%d", &n);
    
    struct node *head, *current, *ptr;
    
    //creating head
    head = (struct node*)malloc(sizeof(struct node));

    if (head == NULL) {

        //checking if the memory is full
        printf("Memory allocation failed\n");
        return 1;
    }

    else if(n>0){
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
    for(int i = 2; i<=n; i++){
        current = (struct node*)malloc(sizeof(struct node));

        if (current == NULL) {

            //checking if tthe memory is full
            printf("Memory allocation failed\n");
            return 1;
        }

        else{
            printf("Enter the element at %d position of the linked list : ", i);
            scanf("%d", &(current->data));
            current->link=NULL;

            //using the ptr to access the previous node until the end of loop
            ptr->link = current;

            //updating the value of ptr
            ptr = current;
        }
    }
}