//linear searching is done on an unsorted list

#include <stdio.h>

int main(){
    int size;
    printf("Enter the size of the list : ");
    scanf("%d", &size);

    int arr[size];
    for(int i=0; i<size; i++){
        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    
    int data;
    printf("Enter the number to be searched : ");
    scanf("%d", &data);

    bool found;

    for(int i=0; i<size; i++){
        if(arr[i]==data){
            printf("Element %d found at arr[%d] position and %d location", data, i, i+1);
            found = 1;
        }
    }
    if (!found) {
        printf("The number %d is not in the list\n", data);
    }

    return 0;

}