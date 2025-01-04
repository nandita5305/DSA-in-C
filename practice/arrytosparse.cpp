//array to sparse matrix representation

#include <stdio.h>

int main(){
    int matrix[3][4] = {
        {0, 3, 5, 0},
        {0, 8, 0, 0},
        {2, 0, 0, 7},
    };

    printf("The given matrix is : \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }

    int count = 0;
    printf("\nThe sparse matrix representation of the matrix is:\nRow Col Val\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(matrix[i][j] != 0){
                printf(" %d ", i);
                printf(" %d ", j);
                printf(" %d ", matrix[i][j]);
                printf("\n");
                count++;
            }
        }
    }
    printf("---------\n 3  4  %d", count);
    return 0;
}