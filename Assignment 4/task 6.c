#include <stdio.h>

int main() {
    int size, i, position, value;

    // Input array size
    printf("Input the size of array : ");
    scanf("%d", &size);

    int arr[100]; // Declare array with extra space for insertion

    // Input array elements
    printf("Input %d elements in the array :\n", size);
    for (i = 0; i < size; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Display current array
    printf("\nThe current list of the array : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input value to be inserted
    printf("Input the value to be inserted : ");
    scanf("%d", &value);

    // Input position to insert
    printf("Input the Position, where the value to be inserted : ");
    scanf("%d", &position);

    // Validate position
    if (position < 1 || position > size + 1) {
        printf("Invalid position! Position should be between 1 and %d\n", size + 1);
        return 1;
    }

    // Convert position from 1-based index to 0-based index
    position = position - 1;

    // Shift elements to make space for new element
    for (i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new value
    arr[position] = value;

    // Increase size
    size++;

    // Display new array
    printf("After Insert the element the new list is : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
