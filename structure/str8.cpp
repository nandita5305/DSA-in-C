//self referential structures

#include <stdio.h>

struct input{
    int data;
    struct input* p;
};

int main(){
    //values inside the structure
    struct input value1, value2;

    value1.data = 32;
    value1.p = NULL;    
    
    value2.data = 3;
    value2.p = NULL;

    //connecting value1 with value2
    value1.p = &value2;

    printf("The data stored in value is : %d and its adress is : %d\n", value1.data, value1.p);
    printf("The data stored in value is : %d and its adress is : %d\n", value1.p->data, value1.p->p);

    return 0;
}