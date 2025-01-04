//exchanging two nodes

#include <stdio.h>
#include <stdlib.h>

//creating node

struct node{
    int data;
    struct node* link;
};

struct node* exchange(struct node* head, struct node* data1, struct node* data2){
    if (data1 == data2){
        return head;
    }

    else{
        int temp;
        temp = data1->data;
        data1->data = data2->data;
        data2->data = temp;
        return head;
    }
}

// Function to check if a number is in the linked list
struct node* search(struct node* head, int num) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == num) {
            return current; // Number found
        }
        current = current->link;
    }
    printf("The number %d is not in the list\n", num);
    return NULL; // Number not found
}

void print(struct node* head){
    if(head == NULL){
        printf("The linked list is empty\n");
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
    int size;
    printf("Enter the number of elements in the linked list : ");
    scanf("%d", &size);
    
    struct node *head, *current, *ptr;
    
    //creating head
    head = (struct node*)malloc(sizeof(struct node));

    if (head == NULL) {

        //checking if the memory is full
        printf("Memory allocation failed\n");
        return 1;
    }

    else if(size>0){
        printf("Enter the element at 1 position of the linked list : ");
        scanf("%d", &(head->data));
        head->link=NULL;

        //storing the adress of head into another pointer so the the value of the head does not change
        ptr = head;

    }

    else{
        printf("No elements in the linked list");
        return 1;
    }
    
    //entering elements in the liked list from 2nd position
    for(int i = 1; i<size; i++){
        current = (struct node*)malloc(sizeof(struct node));

        if (current == NULL) {

            //checking if tthe memory is full
            printf("Memory allocation failed\n");
            return 1;
        }

        else{
            printf("Enter the element at %d position of the linked list : ", i+1);
            scanf("%d", &(current->data));
            current->link=NULL;

            //using the ptr to access the previous node until the end of loop
            ptr->link = current;

            //updating the value of ptr
            ptr = current;
        }
    }

    print(head);

    int n;
    printf("Do you want to exchange numbers in the linked list? 1/0 ");
    scanf("%d", &n);

    if(n==1){
        int data1, data2;
        printf("Enter the first element to swap : ");
        scanf("%d", &data1);
        printf("Enter the second element to swap : "); 
        scanf("%d", &data2);
        struct node* node1 = search(head, data1);
        struct node* node2 = search(head, data2);

        if(node1 != NULL && node2 != NULL){
            head = exchange(head, node1, node2);
            print(head);
        }
    }
    
    return 0;
}