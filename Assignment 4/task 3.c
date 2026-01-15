#include <stdio.h>

int main() {
    int n;

    printf("Print all unique elements of an array:\n");
    printf("------------------------------------------\n");

    // Input number of elements
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("The unique elements found in the array are: ");

    // Check each element for uniqueness
    for(int i = 0; i < n; i++) {
        int isUnique = 1; // Assume element is unique

        // Compare current element with all other elements
        for(int j = 0; j < n; j++) {
            // Skip comparing with itself
            if(i == j) continue;

            // If duplicate found, mark as not unique
            if(arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }

        // If element is unique, print it
        if(isUnique) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");

    return 0;
}
