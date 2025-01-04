//adding at a particular position of the circular LL

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void addatpos(struct node* head, int pos){
    struct node* ptr = head;
    for(int i=0; i<pos-1; i++){
        ptr = ptr->next;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = ptr->next;
    ptr->next = newnode;
    newnode->prev = ptr;
    newnode->next->prev = newnode;
    printf("Input the data at circular LL[%d] : ", pos);
    scanf("%d", &newnode->data);
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
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the data at circular LL[%d] : ", i);
            scanf("%d", &ptr->data);
            ptr->next = head;
            ptr->prev = current;
            current->next = ptr;
            head->prev = ptr;
            current = ptr;
        }

        size++;

        int pos;
        printf("Input the position of the element : ");
        scanf("%d", &pos);

        addatpos(head, pos);

        print(head);
    }
    return 0;
}