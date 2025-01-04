#include <stdio.h>

int main(){
    int size;
    printf("Input the size of queue : ");
    scanf("%d", &size);

    int queue[size];

    int front = -1, rear = -1;

    int n;
    printf("How many numbers do you want in the queue? ");
    scanf("%d", &n);

    if(size>=n && n>0){
        for(int i=0; i<n; i++){
            if(rear == size-1){
                printf("Queue overflow!");
                break;
            }

            rear++; 

            printf("Enter the element to be pushed in the queue : ");
            scanf("%d", &queue[rear]);

            if(i==0){
                front++;
            }
        }
    }
    else{
        printf("Queue overflow!");
    }

    if(front != -1){
        printf("The queue is : ");
        for(int i=front; i<=rear; i++){
            printf(" %d ", queue[i]);
        }
    }

    return 0;
}