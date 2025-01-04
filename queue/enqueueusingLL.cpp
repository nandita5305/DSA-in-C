#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

struct node* createnode(){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Input the data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

struct queue* createqueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue* q){
    struct node* newnode = createnode();

    if(q->rear == NULL){
        q->front = q->rear = newnode;
        return;
    }

    q->rear->next = newnode;
    q->rear = newnode;

}

void dequeue(struct queue* q){
    if(q->front == NULL){
        printf("Queue underflow!");
        return;
    }

    struct node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    free(temp);

    printf("%d dequeued\n", data);

    if(q->front == NULL){
        q->rear == NULL;
    }
}

void display(struct queue* q){
    if(q->front == NULL){
        printf("Queue underflow!");
        return;
    }

    struct node* temp = q->front;
    printf("The queue is : ");
    while(temp!=NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct queue* q = createqueue();

    int size;
    printf("Input the size of queue : ");
    scanf("%d", &size);

    int n;
    printf("How many numbers do you want to enqueue? ");
    scanf("%d", &n);

    if(n>0 && n<=size){
        for(int i=0; i<n; i++){
            enqueue(q);
        }
        display(q);

        for(int i=0; i<n; i++){
            dequeue(q);
            display(q);
        }
    }

    return 0;
}