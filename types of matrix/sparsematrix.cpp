//sparse matrix representation

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns of the sparse matrix : ");
    scanf("%d", &n);
    
    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Enter the value at position matrix[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The sparse matrix is : \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    printf("The sparse matrix representation is : \n");
    printf("  column no. |     row no.    |    value   |\n");
    printf("      %d      |       %d        |      ~     |\n", n, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] != 0){
                printf("      %d      |       %d        |      %d     |\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}