#include <stdio.h>

int main() {
    int N, M, X;

    // Input N, M, and the 2D array
    printf("Enter the number of rows (N) and columns (M): ");
    if (scanf("%d %d", &N, &M) != 2 || N < 2 || N > 100 || M < 2 || M > 100) {
        fprintf(stderr, "Error: Invalid N or M. Please enter values between 2 and 100.\n");
        return 1; // Indicate error
    }

    int A[N][M];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (scanf("%d", &A[i][j]) != 1 || A[i][j] < 1 || A[i][j] >= 100000) {
                fprintf(stderr, "Error: Invalid input. Please enter numbers between 1 and 99999.\n");
                return 1; // Indicate error
            }
        }
    }

    // Input X
    printf("Enter the number to search (X): ");
    if (scanf("%d", &X) != 1 || X < 0 || X >= 1000000) {
        fprintf(stderr, "Error: Invalid X. Please enter a number between 0 and 999999.\n");
        return 1; // Indicate error
    }

    // Search for X in the array
    int found = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (A[i][j] == X) {
                found = 1;
                break; // Found the number, stop searching
            }
        }
    }

    // Print the result
    if (found) {
        printf("will not take number\n"); // X is found in the array
    } else {
        printf("will take number\n"); // X is not found in the array
    }

    return 0;
}
