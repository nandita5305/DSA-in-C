//passing adress of a structure as argument

#include <stdio.h>

struct student{
    char name[10];
    int age;
    int roll;
    float marks;
};


//defining structure of student name P

void print(struct student* P){

    //accessing using (*P).data or P->data

    printf("\nName : %s Age : %d Roll : %d Marks : %0.2f", (*P).name, (*P).age, (*P).roll, (*P).marks);
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

        //passing adress of the structure
        print(&A[i]);
    }
    return 0;
}