//to convert sparse matrix to 2D matrix

#include <stdio.h>

int main(){
    int n, m;
    printf("Input the number of rows of the matrix : ");
    scanf("%d", &n);
    printf("Input the number of columns of the matrix : ");
    scanf("%d", &m);

    int matrix[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrix[i][j]=0;
        }
    }

    int x;
    printf("Input the number of non-zero elements in the matrix : ");
    scanf("%d", &x);

    int a, b;
    printf("\nInput the details of the non-zero elements of the matrix : \n");
    for(int i=0; i<x; i++){
        printf("Enter the row : ");
        scanf("%d", &a);
        printf("Enter the column : ");
        scanf("%d", &b);
        printf("Enter the value : ");
        scanf("%d", &matrix[a][b]);
        printf("\n");
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}