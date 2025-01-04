//deleting the last node of a linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

void addnode(struct node* head, int data){
    struct node* ptr = head;
    while(ptr->link!= NULL){
        ptr = ptr->link;
    }
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = data;
    current->link = NULL;
    ptr->link = current;
}

void deletenode(struct node* head, int size){
    struct node* ptr = head;
    while(ptr->link->link!=NULL){
        ptr = ptr->link;
    }
    ptr->link=NULL;
    free(ptr->link);
}

void print(struct node* head){
    if(head == NULL){
        printf("The linked list is empty");
    }
    struct node* ptr = head;
    printf("The linked list is : {");
    while(ptr != NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("}\n");
}

int main(){
    struct node * head = (struct node*) malloc(sizeof(struct node));
    head->link = NULL;

    int n;
    printf("How many numbers do you want inside the linked list? ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int data;
        printf("Input the number : ");
        scanf("%d", &data);

        if(i==0){
            head->data = data;
        }

        else{
            addnode(head, data);
        }
    }   

    print(head);

    int input;
    printf("Do you want to delete the first member of the list? 1/0 ");
    scanf("%d", &input);
    if(input==1){
        deletenode(head, n);
        print(head);
    }

    return 0; 
} 