#include<stdio.h>

void quicksort(int arr[], int first, int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first, j=last;
      while(i<j){
         while(arr[i]<=arr[pivot] && i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);
   }
}

int main(){
   int i, count, arr[25];
   printf("How many elements are you going to enter?: ");
   scanf("%d",&count);

   for(i=0;i<count;i++){
        printf("Enter value at arr[%d]", i);
        scanf("%d", &arr[i]);
   }

   quicksort(arr, 0, count-1);

   printf("Order of Sorted elements: ");

   for(i=0;i<count;i++)
        printf(" %d",arr[i]);

   return 0;
}