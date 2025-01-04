// square matrix

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns in the square matrix : ");
    scanf("%d", &n);

    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Enter the element at position matrix[%d][%d]", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The square matrix is : \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    return 0;
}