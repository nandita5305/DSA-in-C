//passing structure variable from the function

#include <stdio.h>
#include <string.h>

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

struct student edit(struct student p){

    //changing the value of string requires using strcpy
    strcpy(p.name, "Nandita");
    p.roll=1;
    return p;
};


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

    A[1] = edit(A[1]);

    //note that it will be storing trash values if n=0.TO get meaningful outputs you can create an if-else function to check for the vaue of n
    print(&A[1]);

    return 0;
}