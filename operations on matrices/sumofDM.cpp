//sum of elements of a diagonal matrix

#include <stdio.h>

int main(){
    int n, sum = 0;
    printf("Input the number of rows/columns of the diagonal matrix : ");
    scanf("%d", &n);

    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                printf("Input the elements of the diagonal matrix at matrix[%d][%d]: ", i+1, j+1);
                scanf("%d", &matrix[i][j]);
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }

    for(int i=0; i<n; i++){
        sum += matrix[i][i];
    }
    printf("The sum of the elements of the diagonal matrix is : %d", sum);

    return 0;
}