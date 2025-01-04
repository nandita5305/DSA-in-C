//binary seaarch is done a sorted list

#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = (high + low) / 2; 
        
        if (arr[mid] == target) {
            return mid; 
        } 
        else if (arr[mid] < target) {
            low = mid + 1; 
        } 
        else {
            high = mid - 1;
        }
    }
    
    return -1; 
}

int main() {
    int size, target;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int arr[size];
    
    for(int i=0; i<size; i++){
        printf("Enter the value of arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at position %d\n", target, result + 1); // 1-based index
    } else {
        printf("The number %d is not in the list\n", target);
    }

    return 0;
    
}
