//adding an element into the stack using array

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

    return 0;
}