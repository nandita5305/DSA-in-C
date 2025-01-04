#include <stdio.h>
#include <stdlib.h>

//adding using dynamic memory allocation

int * input(int limit){

    int *ptr = (int*)malloc(limit*sizeof(int));

    //input

    for(int i=0; i<limit; i++){
        printf("Enter the value of element %d : ", i+1);
        scanf("%d", (ptr+i));
    }
    return ptr;
}

int main(){
    
    int i, limit, sum = 0;

    printf("Enter number of elements : ");
    scanf("%d", &limit);

    int *ptr = input(limit);

    //sum

    for( i = 0; i<limit; i++){
        sum= sum+*(ptr+i);
    }

    printf("Sum is : %d", sum);

    free(ptr);

    ptr = NULL;

    return 0;
}