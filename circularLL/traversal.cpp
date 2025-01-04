//traversing a linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

void print(struct node* head){
    int count = 0;
    struct node* ptr = head;
    printf("The circular LL is : {");
    do{
        printf(" %d ", ptr->data);
        ptr = ptr->link;
        count++;
    }while(ptr!=head);
    printf("}\nThe number of elements in the circular LL is : %d", count);
}

int main(){
    int size;
    printf("Input the number of elements in the circular LL : ");
    scanf("%d", &size);

    if(size>0){
        struct node* current;
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the data at circular LL[0] : ");
        scanf("%d", &head->data);
        head->link = head;
        current = head;

        for(int i=1; i<size; i++){
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the data at circular LL[%d] : ", i);
            scanf("%d", &ptr->data);
            current->link = ptr;
            ptr->link = head;
            current = ptr;
        }
        print(head);
    }

    return 0;
}