//tridiagonal matrix

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns in the tridiagonal matrix : ");
    scanf("%d", &n);

    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j or i==j+1 or j==i+1){
                printf("Enter the value at position matrix[%d][%d] : ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }

    printf("The tridiagonal matrix is : \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    return 0;
}