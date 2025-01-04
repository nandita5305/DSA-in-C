//returning pointer from the function of structure

#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void print(struct point* p){
    printf("Number x: %d \nNumber y: %d\n", p->x, p->y);
}

struct point* fun(int a, int b){
    
    //using malloc function to allocate memory so that the pointer does not get destroyed
    struct point* p = (struct point *)malloc(sizeof(struct point));
    p->x = a++;
    p->y = b+20;
    return p;
};

int main(){
    int n;
    printf("Enter the number of data you want to insert : ");
    scanf("%d", &n);

    struct point A[n];

    for(int i=0; i<n; i++){
        printf("Enter the value of x : ");
        scanf("%d", &A[i].x);
        printf("Enter the value of y : ");
        scanf("%d", &A[i].y);
        print(&A[i]);

        //creating a pointer to store the returned value of the function
        struct point* ptr = fun(A[i].x, A[i].y);
        print(ptr);
    }

    return 0;
}