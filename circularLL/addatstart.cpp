//adding at the starting of the linked list 

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
    printf("}\nThe head of the circular LL is : %d", head->data);
}

int main(){
    int size;
    printf("Adding the elements at the start of the node \nInput number of elements int he circular linked list : ");
    scanf("%d", &size);

    if(size>0){
        struct node* current, *tail;
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the data at circular LL[0] : ");
        scanf("%d", &head->data);
        head->link = head;
        current = head;
        tail = head;

        for(int i=1; i<size; i++){
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the data at LL[%d] : ", i);
            scanf("%d", &ptr->data);
            ptr->link = head;
            current = ptr;
            head = ptr;
            tail->link = head; 
        }
        print(head);
    }
    
    return 0;
}