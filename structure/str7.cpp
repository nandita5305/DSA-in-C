//passing structure of arrays into the function

#include <stdio.h>

struct point {
    int x;
    int y;
};

void print(struct point arr[], int size){
    for(int i=0; i<size; i++){
        printf("Point %d Number x: %d Number y: %d\n", i+1, arr[i].x, arr[i].y);
    }
}


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
    }

    print(A,n);

    return 0;
}