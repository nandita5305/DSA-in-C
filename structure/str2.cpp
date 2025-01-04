//passing adresses or calling by reference

#include <stdio.h>

struct student{
    char name[10];
    int age;
    int roll;
    float marks;
};


//dereferencing the pointer

void print(char *name, int *age, int *roll, float *marks){
    printf("\nName : %s Age : %d Roll : %d Marks : %0.2f", name, *age, *roll, *marks);
}

int main(){
    int n;
    printf("\nEnter the number of students in the class : ");
    scanf("%d", &n);

    struct student A[n];

    for(int i=0; i<n; i++){
        printf("\nName of the student : ");
        scanf("%s", A[i].name);
        printf("\nEnter age of the student : ");
        scanf("%d", &A[i].age);
        printf("\nEnter roll number of the student : ");
        scanf("%d", &A[i].roll);
        printf("\nEnter marks of the student : ");
        scanf("%f", &A[i].marks);

        //passing adress of the members
        print(A[i].name, &A[i].age, &A[i].roll, &A[i].marks);
    }
    return 0;
}