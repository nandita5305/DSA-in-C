//scalar  matrix is the one having elements in the diagonal only multiplied to a scalar

#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows/columns in the scalar matrix : ");
    scanf("%d", &n);

    int matrix[n][n];

    int k;
    printf("Input the value of scalar : ");
    scanf("%d", &k);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                matrix[i][j] = k*1;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }

    printf("The scalar matrix is : \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++ ){
            printf(" %d ", matrix[i][j]);
        }
        printf("   \n");
    }
    printf("\n");

    return 0;
}