//adding numbers at the starting of the array

#include <stdio.h>
#include <stdlib.h>


void addatstart(int arr[], int data, int *size){
    for(int i=*size; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = data;
}


void print(int arr[], int size){
    printf("The array is : {");
    for(int i=0; i<size; i++){
        printf(" %d ", arr[i]);
    }
    printf("}\n");
}


int main(){
    int size;
    printf("Enter the number of elements in the list : ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    for(int i=0; i<size; i++){
        printf("Input the value : ");
        scanf("%d", &arr[i]);
        addatstart(arr, arr[i], &size);
    }
    
    print(arr, size);


    int n;
    printf("Do you want to add more numbers in the list? 1/0");
    scanf("%d", &n);
    if(n==1){
        int newsize;
        printf("How many more elements do you wish to add in the list? ");
        scanf("%d", &newsize);

        size = newsize + size;

        arr = (int*)realloc(arr, (size)*sizeof(int));

        for(int i=0; i<newsize; i++){
            int newdata;
            printf("Input value : ");
            scanf("%d", &newdata);
            addatstart(arr, newdata, &size);
        }

    }

    print(arr, size);

    free(arr);
    return 0 ;

}