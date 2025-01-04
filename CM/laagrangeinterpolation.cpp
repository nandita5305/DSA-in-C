//lagrange interpolation method

#include <stdio.h>

double interpolation(int X[], int Y[], int n, int x){
    double sum=0;
    for(int i=0; i<n; i++){
        double product = 1.0;
        for(int j=0; j<n; j++){
            if(i!=j){
                product *= (double)(x-X[j])/(X[i]-X[j]);
            }
        }
        sum += product*Y[i];
    }
    return sum;
}

int main(){
    int n;
    printf("Input the number of data points :  ");
    scanf("%d", &n);

    int X[n], Y[n];

    for(int i=0; i<n; i++){
        printf("Input the value of x%d : ", i);
        scanf("%d", &X[i]);
        printf("Input the value of y%d : ", i);
        scanf("%d", &Y[i]);
    }

    int x;
    printf("Input the value of x for which we need to find y : ");
    scanf("%d", &x);

    double ans = interpolation(X, Y, n, x);

    printf("------------\n X \t Y \t\n");
    for(int i=0; i<n; i++){
        printf(" %d \t %d\t\n", X[i], Y[i]);
    }
    printf("------------\n");

    printf("The value of y is : %f", ans);
    return 0;
}