//upper triangular matrix is a matrix the contains numbers in the places above and in the diagonal

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns in the upper triangular square matrix : ");
    scanf("%d", &n);

    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j or i<j){
                printf("Enter the element at position matrix[%d][%d]", i+1, j+1);
                scanf("%d", &matrix[i][j]);
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }

    printf("The upper triangular matrix is : \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    return 0;
}