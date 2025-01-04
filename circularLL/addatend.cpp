//adding at end of the circular LL

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

void print(struct node* head){
    struct node* ptr = head;
    printf("The circular linked list is : {");
    do{
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);
    printf("}\n");
}


void addatend(struct node* head, int size){
    struct node* current = head;
    for(int i=1; i<size; i++){
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        printf("Input the data at circular LL[%d] : ", i);
        scanf("%d", &ptr->data);
        current->link = ptr;
        ptr->link = head;
        current = ptr;
    }
}

int main(){
    int size;
    printf("Input the size of the linked list : ");
    scanf("%d", &size);

    if(size>0){
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the data at circular LL[0] : ");
        scanf("%d", &head->data);
        head->link = head;

        addatend(head, size);

        print(head);
    }
    return 0;
}