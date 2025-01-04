//creating a node at the strating of the linked list

#include <stdio.h>
#include <stdlib.h>


//node
struct node{
    int data;
    struct node* link;
};


//creating a pointer to a pointer to make the value of the adress stored in the pointer valid
void addatstart(struct node** head, int data){

    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = data;

    //we have saved the adress of head into the pointer to head that is *head
    current->link = *head;

    //to update the head value the pointer to the head needs to be updaated
    *head = current;
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
    printf("Do you want to create a inked list? 1/0");
    scanf("%d", &n);
    if(n==1){
        struct node*head, *ptr;
        head = (struct node*)malloc(sizeof(struct node));
        printf("Input value : ");
        scanf("%d", &(head->data));
        head->link = NULL;

        print(head);

        int m;
        printf("Do you want to add more numbers to the list? /0");
        scanf("%d", &m);

        if(m==1){
            int num;
            printf("How many more lements do you want to add in the list? ");
            scanf("%d", &num);
            for(int i=0; i<num; i++){
                int data;
                printf("Input value : ");
                scanf("%d", &data);

                //inputting the adress of the head to have valid outputs
                addatstart(&head, data);
            }

            print(head);
        }

    }
    return 0;
}