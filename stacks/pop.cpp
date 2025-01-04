//deleting last element

#include <stdio.h>

int size = 3;
int stack[3];
int top = -1;

void push(int element){
    if(top == size-1){
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = element;
    printf("Pushed %d into the stack\n", element);
}

int pop(){
    if(top == -1){
        printf("The stack is empty\n");
        return 0; // Return 0 to indicate no element was popped
    }
    int element = stack[top];
    top--;
    printf("Popped %d from the stack\n", element);
    return element;
}

void print(){
    printf("The stack is : {");
    for(int i=0; i<=top; i++){
        printf(" %d ", stack[i]);
    }
    printf("}\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(9);
    
    print();
    int data = pop();
    printf("The deleted value is : %d\n", data);
    print();

    return 0;
}