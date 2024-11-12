// dropdown for operations on the array

#include <stdio.h>

//print function
void print(int size, int arr[]){
    printf("The array is : {");
    for(int i=0; i<size; i++){
        //printing the elements of the array
        printf(" %d ", arr[i]);
    }
    printf("}\n");
}

//function for adding an element at a position
void addatpos(int data, int pos, int size, int arr[]){
    for(int i=size; i>=pos; i--){
        arr[i] = arr[i-1];
    }
    size++;
    arr[pos] = data;
}

int main(){

    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n); 

    //taking input from user
    int arr[n];
    for(int i=0; i<n; i++){
        int x;
        printf("Enter the value at arr[%d]: ", i);
        scanf("%d", &x);
        arr[i] = x;
    }

    //size of array
    int size = (sizeof(arr)/sizeof(arr[0]));

    print(size, arr);

    for(;;){
        int task;
        printf("\nWhat operation do you want to perform?\n1. Insertion\n2. Deletion\n3.Traversal\n4.EXIT\n");
        scanf("%d", &task);

        if(task==1){
            int data, pos;
            printf("Input the position of the element to be added : ");
            scanf("%d", &pos);
            printf("Input arr[%d] in the array : ", pos);
            scanf("%d", &data);
            addatpos(data, pos, size, arr);

            size++;
            print(size, arr);
        }

        else if(task==2){
            int pos;
            printf("Enter the positon of the element to be deleted : ");
            scanf("%d", &pos);
            for(int i=pos; i<size; i++){
                arr[i] = arr[i+1];
            }

            //decreasing the size by one
            size--;

            printf("Array after deletion is : ");
            print(size, arr);

        }

        else if(task==3){
            print(size,arr);
        }

        else{
            break;
        }
    }

    return 0;

}
