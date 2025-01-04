#include <stdio.h>

float f(float x) {
    return x * x * x - 4 * x - 9;  // Example function: f(x) = x^3 - 4x - 9
}

float bisection(float a, float b) {
    return (a + b) / 2;
}

int main() {
    float a, b, x;
    int iteration = 0;

    // Input the interval [a,b]
    printf("Input the interval [a,b]: ");
    scanf("%f %f", &a, &b);

    // Check if the assumption of the interval is correct
    if (f(a) * f(b) >= 0) {
        printf("You have assumed the wrong interval.\n");
        return 1;
    }

    // Print the header for the table
    printf("\nIter\t a\t\t b\t\t x (mid)\t f(a)\t\t f(b)\t\t f(x)\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    // Perform the Bisection Method
    while ((b - a) >= 0.0001) {
        x = bisection(a, b);  // Midpoint
        iteration++;

        // Print the current iteration, a, b, x, f(a), f(b), and f(x)
        printf("%d\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\t %.4f\t\t %.4f\n", 
               iteration, a, b, x, f(a), f(b), f(x));

        // Check which subinterval contains the root
        if (f(a) * f(x) < 0) {
            b = x;  // Root lies in [a, x]
        } else {
            a = x;  // Root lies in [x, b]
        }
    }

    // Print the final result
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Approximate root found is in interval: [%.4f, %.4f]\n", a, b);
    printf("The root is approximately: %.4f\n", x);

    return 0;
}
