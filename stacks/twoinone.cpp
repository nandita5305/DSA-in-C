#include <stdio.h>

int stack[20];
int stack1[5];
int stack2[5];
int top1 = -1;
int top2 = -1;
int top = -1;

int isempty(int top){
    return top == -1;
}

int isfull(int top, int size){
    return top == size - 1;
}

void push(int stack[], int *top, int data, int size){
    if(isfull(*top, size)){
        printf("Stack overflow!\n");
        return;
    }
    (*top)++;
    stack[*top] = data;
    printf("Pushed %d onto the stack\n", data);
}

int pop(int stack[], int *top){
    if(isempty(*top)){
        printf("Stack underflow!\n");
        return -1;
    }
    int data = stack[*top];
    (*top)--;
    return data;
}

void peek(int stack[], int top){
    if(isempty(top)){
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void print_stack(int stack[], int top){
    if(isempty(top)){
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are: ");
        for(int i = 0; i <= top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void combine_stacks(){
    // Combine stack1 and stack2 into one big stack
    printf("Combining stack1 and stack2 into stack...\n");
    for(int i = 0; i <= top1; i++){
        push(stack, &top, stack1[i], 20);  // pushing stack1 into big stack
    }
    for(int i = 0; i <= top2; i++){
        push(stack, &top, stack2[i], 20);  // pushing stack2 into big stack
    }
}

int main(){
    int choice, data;
    
    while(1){
        printf("\nOperations on stack1 or stack2: ");
        printf("\n\n1. Push into stack1\n2. Push into stack2\n3. Pop from stack1\n4. Pop from stack2\n");
        printf("5. Peek top of stack1\n6. Peek top of stack2\n7. Print stack1\n8. Print stack2\n9. Combine stacks\n10. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("Input data to be pushed in stack1: ");
                scanf("%d", &data);
                push(stack1, &top1, data, 5);
                break;

            case 2: 
                printf("Input data to be pushed in stack2: ");
                scanf("%d", &data);
                push(stack2, &top2, data, 5);
                break;

            case 3: 
                data = pop(stack1, &top1);
                if (data != -1)
                    printf("Popped %d from stack1\n", data);
                break;

            case 4: 
                data = pop(stack2, &top2);
                if (data != -1)
                    printf("Popped %d from stack2\n", data);
                break;

            case 5: 
                peek(stack1, top1);
                break;

            case 6: 
                peek(stack2, top2);
                break;

            case 7: 
                print_stack(stack1, top1);
                break;

            case 8: 
                print_stack(stack2, top2);
                break;

            case 9: 
                combine_stacks();
                print_stack(stack, top);
                break;

            case 10: 
                printf("Exiting...\n");
                return 0;

            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
