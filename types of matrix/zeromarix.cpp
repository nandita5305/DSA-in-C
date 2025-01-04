//zero matrix is a matrix that has all elements equal to zero

#include <stdio.h>

int main(){
    int row, column;
    printf("Enter the number of rows and columns of the zero matrix : ");
    scanf("%d %d", &row, &column);

    int matrix[row][column];
    
    for(int i=0; i<=row; i++){
        for(int j=0; j<=column; j++){
            matrix[i][j] = 0;
        }
    }

    printf("The zero matrix is : \n\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    return 0;
}