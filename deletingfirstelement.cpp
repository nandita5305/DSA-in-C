//deleting first node of the array

# include <stdio.h>

void deletefirst(int arr[], int size){
    for(int i=0; i<size; i++){
        arr[i] = arr[i+1];
    }
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

    int size = (sizeof(arr)/sizeof(arr[0]));

    printf("The array after deleting the first element of the array is : {");
    deletefirst(arr, size);

    for(int i=0; i<size-1; i++){
        //printing the elements of the array
        printf(" %d ", arr[i]);
    }
    printf("}");

    return 0;

}
