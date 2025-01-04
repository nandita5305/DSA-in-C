//addition of two square matrices 

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns in the square matrix : ");
    scanf("%d", &n);

    int matrix1[n][n];
    int matrix2[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Enter the element at position matrix1[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Enter the element at position matrix2[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Adding the two matrix : \n\n");
    printf("        +           =\n");
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
            printf(" %d ", matrix1[i][k]+matrix2[i][k]);
        }
        printf("   \n");
    }
    printf("\n");

    return 0;
}