#include <stdio.h>

int *func1(int n){
    int *ptr = &n;
    return ptr;
}

int main(){
    printf("%d", func1(5));
    printf("The value returned is dangling as the adress value is valid to func1 and local to that function. Its existence outside the function is ivaid and ence the code will return a garbage value");
    return 0;
}