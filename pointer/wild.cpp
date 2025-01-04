#include <stdio.h>
#include <stdlib.h>

//method to change the value of the adress stored inside the pointer

int main(){
    int *ptr;
    *ptr = 10;
    printf("Here we are trying to dereference the pointer and store the value in the pointer to the pointer hence it is called a wild pointer\n");
    

    //instead 1 - initialise variable

    int *ptr1;
    int num = 10;
    ptr1 = &num;
    printf("%d is the adress of num=10\n", ptr1);

    //instead 2 - explicit mehtod

    int *ptr2 = (int*)malloc(sizeof(int));
    *ptr2 = 20;
    printf("%d is the adress of num=20", ptr2);
    free(ptr2);

    return 0;
}