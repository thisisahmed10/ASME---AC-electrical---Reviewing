#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two integer numbers (separated by space): ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Error: Invalid input. Please enter two integers.\n");
        return 1; // Indicate error
    }

    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
    printf("%d / %d = %f\n", num1, num2, (float)num1 / (float)num2); // Integer division

    return 0;
}
