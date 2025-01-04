//deleting a particular node of the circular LL

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void addatend(struct node* head, int i){
    struct node* ptr = head;
    do{
        ptr = ptr->next;
    }while(ptr->next!=head);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Input the data at circular LL[%d] : ", i);
    scanf("%d", &newnode->data);

    newnode->next = head;    
    newnode->prev = ptr;
    ptr->next = newnode;
    head->prev = newnode;    
}

struct node* deletenode(struct node* head, int pos){
    struct node* ptr = head;
    if (head->next == head) {
        free(head);
        return NULL; 
    }

    if (pos==0){
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        return head;
    }

    for(int i=0; i<pos; i++){
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return head;
}

void print(struct node* head){
    struct node* ptr = head;
    printf("The circular linked list is : {");
    do{
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
    printf("}\n");
}

int main(){
    int size;
    printf("Input the size of the circular LL : ");
    scanf("%d", &size);

    if (size>0){
        struct node* current;
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the data at circular LL[0] : ");
        scanf("%d", &head->data);
        head->prev = head;
        head->next = head;
        current = head;

        for(int i=1; i<size; i++){
            addatend(head, i);
        }

        int pos;
        printf("Enter the position of the circularLL to be deleted : ");
        scanf("%d", &pos);

        head = deletenode(head, pos);

        print(head);
    }

    return 0;
}