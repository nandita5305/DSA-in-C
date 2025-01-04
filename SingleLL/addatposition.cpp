//adding at a particular position

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

void addatend(struct node* head, int data){
    struct node* temp = head;
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = data;
    current->link = NULL;
    while(temp->link !=NULL){
        temp = temp->link;
    }
    temp->link = current;
}

void print(struct node* head){
    struct node* ptr = head;
    printf("The linked list is : {");
    while(ptr!=NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("}\n");
}

void addatposition(struct node** head, int data, int position){

    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->link = NULL;

    if(position == 0){
        newnode->link = *head;
        *head = newnode;
        return;
    }

    struct node* ptr = *head;
    if (ptr == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }
    for(int i=0; i<position-1; i++){
        if (ptr == NULL) {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
        ptr = ptr->link;
    }

    newnode->link = ptr->link;
    ptr->link = newnode;

}

int main(){
    int n;
    printf("Do you want to create a linked list? 1/0");
    scanf("%d", &n);
    if (n==1){
        int size;
        printf("How many numbers do you want to be inside the list? ");
        scanf("%d", &size);
        if (size>0){
            struct node* head = (struct node*)malloc(sizeof(struct node));
            printf("Input the value : ");
            scanf("%d", &head->data);
            head->link =NULL;

            for(int i = 1; i<size; i++){
                int data;
                printf("Input the value : ");
                scanf("%d", &data);
                addatend(head, data);
            }

            print(head);

            printf("Do you want to add a number at a specific position? 1/0: ");
            scanf("%d", &n);

            if (n == 1) {
                int pos, newdata;
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the value: ");
                scanf("%d", &newdata);
                addatposition(&head, newdata, pos);
            }

            print(head);

        }
    }
    return 0 ;
}