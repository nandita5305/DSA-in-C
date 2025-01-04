//counting or traversing the circular LL

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

void print(struct node* head){
    struct node* ptr = head;
    int count = 0;
    printf("The circular linked list is : {");
    do{
        printf(" %d ", ptr->data);
        ptr = ptr->next;
        count++;
    }while(ptr!=head);
    printf("}\nThe number of elements in the ciruclar LL is %d", count);
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

        print(head);
    }
    return 0;
}