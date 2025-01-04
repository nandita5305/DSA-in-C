//push pop isempty isfull peek function implementation using linked list 

#include <stdio.h>
#include <stdlib.h>

//structure to define a stack
struct node{
    int data;
    struct node* link;
};

struct node* top = NULL;

//inserting an element into the stack
void push(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("Stack overflow!\n");
        return;
    }
    newnode->data = value;
    newnode->link = top;
    top = newnode;
}

//to check if stack is empty or not
int isempty(){
    if(top==NULL){
        printf("The stack is empty");
        return 1;
    }
    else {
        printf("Stack is not empty.\n");
        return 0;
    }
    
}

//to delete topmost element of the stack
int pop(){
    if(top==NULL){
        printf("The stack is empty.\n");
        return -1;
    }
    struct node* temp = top;
    int data = temp->data;
    top = top->link;
    free(temp);
    return data;
}

//to see the topmost element of the stack
int peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

//to print the stack
void print() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node* temp = top;  
    printf("Stack elements: ");
    while (temp != NULL) {    
        printf("%d ", temp->data); 
        temp = temp->link;    
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);

    print();

    printf("Top element is %d\n", peek()); 
    
    printf("Popped %d from the stack\n", pop()); 
    print();

    printf("Popped %d from the stack\n", pop());
    print();  
    
    isempty();

    printf("Popped %d from the stack\n", pop()); 
    print();
    
    isempty();
    
    return 0;
    
}
