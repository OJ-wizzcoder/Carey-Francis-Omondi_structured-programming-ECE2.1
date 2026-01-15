#include <stdio.h>

int main() {
    int n, i;

    // Input the number of elements
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Input %d elements in the array :\n", n);
    for(i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with first element
    int max = arr[0];
    int min = arr[0];

    // Find maximum and minimum
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Display results
    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d\n", min);

    return 0;
}
