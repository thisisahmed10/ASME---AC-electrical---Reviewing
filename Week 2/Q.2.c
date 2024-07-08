#include <stdio.h>

int main() {
    float num;

    printf("Enter a float number: ");
    if (scanf("%f", &num) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter a float number.\n");
        return 1; // Indicate error
    }

    // Check if the difference between the number and its integer part is negligible
    if (fabs(num - (int)num) < 1e-6) {  // Tolerance for floating-point precision
        printf("Integer\n");
    } else {
        printf("Float\n");
    }

    return 0;
}
