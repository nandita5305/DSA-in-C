//searching the element 

#include <stdio.h>
#include <stdlib.h>

//defining structure
struct node{
    int data;
    struct node* link;
};

int find(struct node* head, int element){
    struct node* ptr = head;
    int count=0;
    do {
        if (ptr->data == element) {
            printf("The element is found at position: %d\n", count);
            return count;
        }
        ptr = ptr->link;
        count++;
    } while (ptr != head);
    printf("Element not found\n");
    return -1;
}

//print function
void print(struct node* head, int size){
    struct node* ptr = head;
    printf("The circular linked list is {");
    for(int i=0; i<size; i++){
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("}\n");
}

int main(){
    int size;
    printf("How many numbers do you want inside the list? ");
    scanf("%d", &size);

    if(size>0){
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the value of head : ");
        scanf("%d", &head->data);

        struct node* ptr, *current = head;

        for(int i=0; i<size-1; i++){
            ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the value of element : ");
            scanf("%d", &ptr->data);

            current->link = ptr;
            current = ptr;
        }
        current->link = head;
        print(head, size);

        int element;
        printf("Enter the element to be found : ");
        scanf("%d", &element);

        find(head, element);

    }

    return 0;
}