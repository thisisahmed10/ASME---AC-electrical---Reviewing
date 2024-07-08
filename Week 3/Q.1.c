#include <stdio.h>

int count_ones(int num) {
    int count = 0;
    while (num) {
        count += num & 1;  // Check the least significant bit (LSB)
        num >>= 1;          // Right shift by 1 to move to the next bit
    }
    return count;
}

int main() {
    int N, num;

    printf("Enter the number of integers (N): ");
    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1; // Indicate error
    }

    for (int i = 0; i < N; ++i) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &num) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
            return 1; // Indicate error
        }

        int ones_count = count_ones(num);
        printf("Number of ones in %d: %d\n", num, ones_count);
    }

    return 0;
}
