//entering the node at the end of the linked list 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

void print(struct node* head){
    struct node* ptr = head;
    printf("The elements of the linked list are : {");
    while(ptr!=NULL){
        printf(" %d ", (ptr->data));
        ptr = ptr->link;
    }

    printf("}\n");
}

void add(struct node* head, int data){
    struct node* ptr, *temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while((ptr->link)!= NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

int main(){
    int n;
    printf("Do you want to create a linked list? 1/0 ");
    scanf("%d", &n);
    
    struct node *head = NULL;

    if (n==1){
        int size;
        printf("Enter the number of elements inside the list : ");
        scanf("%d", &size);

        //struct node* head = (struct node*)malloc(sizeof(struct node));

        if(size>0){
            head = (struct node*)malloc(sizeof(struct node));
            printf("Input the value of element : ");
            scanf("%d", &(head->data));
            head->link = NULL;

            struct node* ptr = head;

            for(int i=1; i<size; i++){
                struct node* current = (struct node*)malloc(sizeof(struct node));
                printf("Input the value of element : ");
                scanf("%d", &(current->data));
                current->link = NULL;
                ptr->link = current;
                ptr = current;
            }
            print(head);

            int x,y;
            printf("Do you want to add a new number to the list? 1/0 ");
            scanf("%d", &x);
            if(x==1){
                printf("Input the value : ");
                scanf("%d", &y);
                add(head, y);
                print(head);
                return 1;
            }
            else{
                return 1;
            }
        }
        else{
            printf("List size must be reater than o. \n");
        }
    }
    return 0;
}
