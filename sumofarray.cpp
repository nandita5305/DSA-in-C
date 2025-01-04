// sum of numbers of an array

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

    int sum =0;
    for(int i=0; i<size; i++){
        sum+= arr[i];
    }
    printf("The sum of the numbers of the array is : %d", sum);

    return 0;

}
