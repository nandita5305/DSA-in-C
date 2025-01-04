//push pop isempty isfull peek function implementation using arrays

#include <stdio.h>

int size = 3;
int stack[3];
int top = -1;

//helps to insert into the stack
void push(int element){
    if(top == size-1){
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = element;
    printf("Pushed %d into the stack\n", element);
}

//helps to delete topmost element
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

//to check if stack is empty
void isempty(){
    if(top == -1){
        printf("Stack is empty\n");
    } else {
        printf("Stack has %d elements\n", top + 1);
    }
}

//to check if stack is full
void isfull(){
    if(top == size - 1){
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
    }
}

//helps to print the stack
void print(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("The stack is: {");
    for(int i = 0; i <= top; i++){
        printf(" %d ", stack[i]);
    }
    printf("}\n");
}

//helps to see the topmost element
void peek(){
    if(top == -1){
        printf("Stack is empty, no element to peek\n");
    } else {
        printf("The top element is %d\n", stack[top]);
    }
}

int main() {
    push(5);
    push(10);
    push(15);
    print();
    peek();
    pop();
    isempty();
    isfull();
    push(20);
    print();
    peek();
    return 0;

}
