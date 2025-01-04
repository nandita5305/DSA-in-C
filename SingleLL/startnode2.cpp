//creating a node at the strating of the linked list - easy

#include <stdio.h>
#include <stdlib.h>


//node
struct node{
    int data;
    struct node* link;
};


//function to add a node at the starting of the linked list
struct node* addatstart(struct node* head, int data){

    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = data;
    current->link = head;

    //to update the head value 
    head = current;

    //this function return a pointer to the structure
    return head;
}


// Function to print the linked list
void print(struct node* head) {
    struct node* ptr = head;
    printf("The elements in the list are: {");
    while (ptr != NULL) {
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("}\n");
}

int main(){
    int n;
    printf("Do you want to create a inked list? 1/0 ");
    scanf("%d", &n);
    if(n==1){
        struct node*head, *ptr;
        head = (struct node*)malloc(sizeof(struct node));
        printf("Input initial value : ");
        scanf("%d", &(head->data));
        head->link = NULL;

        print(head);

        int m;
        printf("Do you want to add more numbers to the list? 1/0 ");
        scanf("%d", &m);

        if(m==1){

            int num;
            printf("How many more lements do you want to add in the list? ");
            scanf("%d", &num);

            for(int i=0; i<num; i++){
                int data;
                printf("Input value : ");
                scanf("%d", &data);

                //updating the vale of head everytime
                head = addatstart(head, data);
            }

            print(head);
        }

    }
    return 0;
}