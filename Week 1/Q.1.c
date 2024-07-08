#include <stdio.h>

int main() {
    int num, sum = 0, i;

    printf("Enter an integer number: ");
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer number.\n");
        return 1; // Indicate error
    }

    // Calculate the sum

    printf("The sum of numbers between 1 and %d is %d\n", num, num*(num+1)/2);

    return 0;
}
