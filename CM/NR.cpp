#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001  // Tolerance level to stop the iteration

// Define the function for which we want to find the root
double function(double x) {
    return x * x *x - x - 1;  // Example: f(x) = x^2 - 4
}

// Define the derivative of the function
double derivative(double x) {
    return 2 * x;  // Example: f'(x) = 2x
}

// Custom function to compute the absolute value of the difference
double absolute(double value) {
    if (value < 0) {
        return -value;  // If negative, make it positive
    }
    return value;      // Otherwise, return the same value
}

int main() {
    double x0, x1;  // x0 is the initial guess, x1 is the updated value
    int maxIterations, iteration = 0;

    // Input initial guess and max iterations
    printf("Enter the initial guess: ");
    scanf("%lf", &x0);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Print the header for the table
    printf("\nIteration\t x\t\t f(x)\t\t f'(x)\t\t x_new\n");
    printf("--------------------------------------------------------------\n");

    while (iteration < maxIterations) {
        // Calculate the next approximation using the Newton-Raphson formula
        x1 = x0 - function(x0) / derivative(x0);

        // Print the current iteration, x0, f(x0), f'(x0), and x1 (new x)
        printf("%d\t\t %.6lf\t %.6lf\t %.6lf\t %.6lf\n", iteration + 1, x0, function(x0), derivative(x0), x1);

        // If the absolute difference between current and previous value is small, stop
        if (absolute(x1 - x0) < EPSILON) {
            break;
        }

        // Update x0 for the next iteration
        x0 = x1;
        iteration++;
    }

    // Final result
    printf("--------------------------------------------------------------\n");
    printf("The root is approximately: %.6lf\n", x1);

    return 0;
}
