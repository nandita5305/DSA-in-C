//deleting first node of the circular linked list 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* deletefirst(struct node* head){
    struct node* temp = head;
    struct node* ptr = head;
    while(ptr->link!=head){
        ptr = ptr->link;
    }
    head = head->link;
    ptr->link = head;
    free(temp);
    return head;
}

void print(struct node* head){
    struct node* ptr = head;
    printf("The circular linked list is : {");
    do{
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);
    printf("}\n");
}

int main(){
    int size;
    printf("Input the number of elements in the circular LL : ");
    scanf("%d", &size);

    if(size>0){
        struct node* current;
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the data of circular LL[0] : ");
        scanf("%d", &head->data);
        head->link = head;
        current = head;

        for(int i=1; i<size; i++){
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the data of circular LL[%d] : ", i);
            scanf("%d", &ptr->data);
            ptr->link = head;
            current->link = ptr;
            current = ptr;
        }

        head = deletefirst(head);

        print(head);

    }
    return 0;
}