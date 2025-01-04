//column matrix contains all elements in its column only

#include <stdio.h>

int main(){
    int row, column=1;
    printf("Enter the number of columns in the matrix : ");
    scanf("%d", &row);

    int matrix[row][column];

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("Enter the value of the element at matrix[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The column matrix is : [");
    for(int i=0; i<row; i++){
        for(int j=0; j<column ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
    }
    printf("]\n");

    return 0;
}