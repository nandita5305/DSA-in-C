// row matrix is a matrix containing elements in the row only

#include <stdio.h>

int main(){
    int row=1, column;
    printf("Enter the number of elements in the row matrix : ");
    scanf("%d", &column);

    int matrix[row][column];

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++ ){
            printf("Enter the number at position matrix[%d][%d] ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The row matrix is : [");
    for(int i=0; i<row; i++){
        for(int j=0; j<column ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
    }
    printf("]\n");

    return 0;
}