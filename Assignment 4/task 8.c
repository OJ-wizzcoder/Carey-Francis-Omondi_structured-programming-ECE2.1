#include <stdio.h>

#define ROWS 6
#define COLS 4

int main() {
    // Create and initialize a 2D array in one step
    int array[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    // Traverse and print with indices
    printf("Traversing the 2D array:\n");
    printf("------------------------\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("array[%d][%d] = %d\n", i, j, array[i][j]);
        }
    }

    // Print in matrix format
    printf("\nMatrix format:\n");
    printf("-------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", array[i][j]);  // %3d for proper alignment
        }
        printf("\n");
    }

    return 0;
}
