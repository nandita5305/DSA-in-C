//searching the element 

#include <stdio.h>
#include <stdlib.h>

//defining structure
struct node{
    int data;
    struct node* link;
};

void find(struct node* head, int pos){
    struct node* ptr = head;
    for(int i=0; i<pos-1; i++){
        ptr= ptr->link;
    }
    printf("The element is : %d ", ptr->link->data);
}

//print function
void print(struct node* head, int size){
    struct node* ptr = head;
    printf("The circular linked list is {");
    for(int i=0; i<size; i++){
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("}\n");
}

int main(){
    int size;
    printf("How many numbers do you want inside the list? ");
    scanf("%d", &size);

    if(size>0){
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the value of head : ");
        scanf("%d", &head->data);

        struct node* ptr, *current = head;

        for(int i=0; i<size-1; i++){
            ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the value of element : ");
            scanf("%d", &ptr->data);

            current->link = ptr;
            current = ptr;
        }
        current->link = head;
        print(head, size);

        int pos;
        printf("Enter the pos of element : ");
        scanf("%d", &pos);

        if(pos<=size){
            find(head, pos);
        }
        else{
            printf("Out of range");
        }

    }

    return 0;
}