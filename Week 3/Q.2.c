#include <stdio.h>

int main() {
    int N;

    printf("Enter the number of rows (N): ");
    if (scanf("%d", &N) != 1 || N < 1 || N > 99) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer between 1 and 99.\n");
        return 1; // Indicate error
    }

    // Handle both even and odd N for a complete diamond
    int spaces = N - 1; // Initial number of spaces
    int stars = 1; // Initial number of stars

    for (int i = 1; i <= N * 2; ++i) {
        // Print leading spaces
        for (int j = 1; j <= spaces; ++j) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= stars; ++j) {
            printf("*");
        }

        printf("\n");
        int c = 0;
        if (i < N) {
            spaces--;
            stars += 2;
        } else if (i == N && c < 2) {
            c++;
        } else {
            spaces++;
            stars -= 2;
        }
    }

    return 0;
}
