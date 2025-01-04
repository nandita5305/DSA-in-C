//transpose of a matrix

#include <stdio.h>

int main(){
    int row, column;
    printf("Enter the number of rows and columns of the rectanglar matrix : ");
    scanf("%d %d", &row, &column);
    
    int matrix[row][column];

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("Enter the value at position matrix[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The rectangular matrix is : \n\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    printf("The transpose of the matrix is : \n\n");
    int temp;
    temp = row;
    row = column;
    column = temp;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf(" %d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}