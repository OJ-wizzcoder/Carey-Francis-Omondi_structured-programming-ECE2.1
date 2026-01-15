#include <stdio.h>

int main() {
    int n;

    // Input the number of elements
    printf("Input the number of elements to store in the array : ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("\nInput %d number of elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nThe values store into the array are : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display array in reverse order
    printf("\nThe values store into the array in reverse are : ");
    for(int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
