#include <stdio.h>

// Define the function for which we want to find the root
float f(float x) {
    return x * x * x - 4 * x - 9;  // Example: f(x) = x^3 - 4x - 9
}

// Function to calculate the absolute value
float abs_value(float x) {
    return (x >= 0) ? x : -x;
}

int main() {
    float x0, x1, x2, f0, f1;
    int iteration = 0;
    const float TOL = 0.0001;   // Tolerance level for stopping criterion
    const int MAX_ITER = 1000;  // Maximum number of iterations

    // Input two initial guesses
    printf("Enter the initial guesses x0 and x1: ");
    scanf("%f %f", &x0, &x1);

    // Print the header for the table
    printf("\nIter\t x0\t\t x1\t\t x2 (mid)\t  f(x0)\t\t  f(x1)\t\t  f(x2)\n");
    printf("---------------------------------------------------------------------------------------------------\n");

    // Secant method iterations
    do {
        f0 = f(x0);  // f(x0)
        f1 = f(x1);  // f(x1)

        // Check if the denominator is zero to avoid division by zero
        if (abs_value(f1 - f0) < TOL) {
            printf("Denominator is too small, method fails.\n");
            return -1;
        }

        // Secant method formula to find next approximation
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        // Print iteration details
        printf("%-4d\t %-10.6f\t %-10.6f\t %-10.6f\t %-10.6f\t %-10.6f\t %-10.6f\n", 
               iteration + 1, x0, x1, x2, f0, f1, f(x2));

        // Update x0 and x1 for the next iteration
        x0 = x1;
        x1 = x2;

        iteration++;

        // Stop if maximum iterations are reached
        if (iteration > MAX_ITER) {
            printf("Method did not converge within the maximum iterations.\n");
            return -1;
        }
    } while (abs_value(f(x2)) > TOL);  // Stop if the function value is close to 0

    // Print the final result
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Approximate root found is: %.6f\n", x2);

    return 0;
}
