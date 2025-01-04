//deleting an intermediate node

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* deletenode(struct node* head, int pos){
    struct node* temp = head;
    struct node* ptr = head;
    if(pos==0){
        if (head->link == head){ 
            free(head);
            return NULL;
        }
        while(ptr->link!=head){
            ptr = ptr->link;
        }
        head = head->link;
        ptr->link = head;
        free(temp);
        return head;
    }
    for(int i=0; i<pos-1; i++){
        ptr=ptr->link;
    }
    temp = ptr->link;
    ptr->link = ptr->link->link;
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

        int pos;
        printf("Input the position to delete an element : ");
        scanf("%d", &pos);
        
        if(pos<=size){
            head = deletenode(head, pos);
            print(head);
        }

    }
    return 0;
}