#include <stdio.h>

int main() {
    int size;

    // Input array size
    printf("Input the size of array : ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Input %d elements in the array :\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Sort array in ascending order using Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    printf("\nElements of array in sorted ascending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
