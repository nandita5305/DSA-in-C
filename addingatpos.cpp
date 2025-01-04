//adding at a particular position

#include <stdio.h>

void addatpos(int data, int pos, int size, int arr[]){
    for(int i=size; i>=pos; i--){
        arr[i] = arr[i-1];
    }
    size++;
    arr[pos] = data;
}

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

    int data, pos;
    printf("Input the position of the element to be added : ");
    scanf("%d", &pos);
    printf("Input arr[%d] in the array : ", pos);
    scanf("%d", &data);
    addatpos(data, pos, size, arr);

    size++;
    print(size, arr);

    return 0;

}
