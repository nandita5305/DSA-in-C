//identity matrix contains 1 in the diagonal and rest of the elements are zero

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns in the identity matrix : ");
    scanf("%d", &n);

    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }

    printf("The identity matrix is : \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    return 0;
}