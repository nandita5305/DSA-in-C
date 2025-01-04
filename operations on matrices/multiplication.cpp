//multiplication of two square matrices 

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns in the square matrix : ");
    scanf("%d", &n);

    int matrix1[n][n];
    int matrix2[n][n];
    int product[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Enter the element at position matrix[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Enter the element at position matrix[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            product[i][j] = 0;
        }
    }

    for(int k=0; k<n; k++){
        for(int l=0; l<n; l++){
            for(int m=0; m<n; m++){
                product[k][l] += matrix1[k][m]*matrix2[m][l];
            }
        }
    }

    printf("product the two matrix : \n\n");
    printf("        X           =\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++ ){
            printf(" %d ", matrix1[i][j]);
        }
        printf("     ");
        for(int j=0; j<n; j++){
            printf(" %d ", matrix2[i][j]);
        }
        printf("      ");
        for(int k=0; k<n; k++){
            printf(" %d ", product[i][k]);
            }
        printf("   \n");
    }
    
    printf("\n");

    return 0;
}