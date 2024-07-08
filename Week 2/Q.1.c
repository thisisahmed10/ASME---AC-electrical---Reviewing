#include <stdio.h>

int main() {
    int num1, num2, num3, num4;

    printf("Enter four integer numbers (separated by space): ");
    if (scanf("%d %d %d %d", &num1, &num2, &num3, &num4) != 4) {
        fprintf(stderr, "Error: Invalid input. Please enter four integers.\n");
        return 1; // Indicate error
    }

    // Check for increasing or decreasing sequential order
    if ((num2 == num1 + 1 && num3 == num2 + 1 && num4 == num3 + 1) ||
        (num2 == num1 - 1 && num3 == num2 - 1 && num4 == num3 - 1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
