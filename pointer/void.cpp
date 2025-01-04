#include <stdio.h>

int main(){
    int n = 4;
    void *ptr = &n;
    printf("The pointer ptr is a void pointer as its datatype is not specified");
    return 0;
}