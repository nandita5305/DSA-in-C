//to perform addition multiplication and transpose of 2D matrix

#include <stdio.h>

int main(){
    int m, n;
    printf("Input the number of rows in the 2D arrays : ");
    scanf("%d", &m);
    printf("Input the number of columns in the 2D arrays : ");
    scanf("%d", &n);

    int arr1[m][n], arr2[m][n], product[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Input the value at arr1[%d][%d] : ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Input the value at arr2[%d][%d] : ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            product[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                product[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nThe sum of the matrices is : \n");
    printf("        +         =\n");
    for(int i =0; i<m; i++){
        for(int j=0; j<n; j++){
            printf(" %d ", arr1[i][j]);
        }
        printf("    ");
        for(int j=0; j<n; j++){
            printf(" %d ", arr2[i][j]);
        }
        printf("    ");
        for(int j=0; j<n; j++){
            printf(" %d ", arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }

    printf("\nThe multiplication of the matrices is : \n");
    printf("        X         =\n");
    for(int i =0; i<m; i++){
        for(int j=0; j<n; j++){
            printf(" %d ", arr1[i][j]);
        }
        printf("    ");
        for(int j=0; j<n; j++){
            printf(" %d ", arr2[i][j]);
        }
        printf("    ");
        for(int j=0; j<n; j++){
            printf(" %d ", product[i][j]);
        }
        printf("\n");
    }
    
    printf("\nTranspose of the matrix is : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf(" %d ", arr1[j][i]);
        }
        printf("\n");
    }
    return 0;
}