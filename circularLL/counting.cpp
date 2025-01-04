// counting the number of nodes in a circular LL

#include <stdio.h>
#include <stdlib.h>

//defining structure
struct node{
    int data;
    struct node* link;
};

//print function
void print(struct node* head, int size){
    struct node* ptr = head;
    int count = 0;
    printf("The circular linked list is {");
    for(int i=0; i<size; i++){
        printf(" %d ", ptr->data);
        ptr = ptr->link;
        count++;
    }
    printf("}\nThe number of elements in the circular LL is %d ", count);
}

int main(){
    int size;
    printf("How many numbers do you want inside the list? ");
    scanf("%d", &size);

    if(size>0){
        struct node* head = (struct node*)malloc(sizeof(struct node));
        printf("Input the value of element at circular LL[0] : ");
        scanf("%d", &head->data);

        struct node* ptr, *current = head;

        for(int i=1; i<size; i++){
            ptr = (struct node*)malloc(sizeof(struct node));
            printf("Input the value of element at circular LL[%d] : ", i);
            scanf("%d", &ptr->data);

            current->link = ptr;
            current = ptr;
        }
        current->link = head;
        print(head, size);
    }

    return 0;
}