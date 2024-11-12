//deleting last element of an array

# include <stdio.h>

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

    //counting the number of elements in the array
    int size = (sizeof(arr)/sizeof(arr[0]));
    size = size - 1;

    printf("The elements of the array are after deleting the last element is : {");
    for(int i=0; i<size; i++){
        //printing the elements of the array
        printf(" %d ", arr[i]);
    }
    printf("}");

    return 0;
    
}