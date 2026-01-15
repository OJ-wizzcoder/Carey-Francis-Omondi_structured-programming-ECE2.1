#include <stdio.h>

#define BUFFER_SIZE 5

// Structure to hold the circular buffer
typedef struct {
    int buffer[BUFFER_SIZE];
    int head;  // Index where the newest element is stored
    int tail;  // Index where the oldest element is stored
    int count; // Number of elements currently in buffer
    int isFull; // Flag to indicate if buffer is full
} CircularBuffer;

// Function to initialize the circular buffer
void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    cb->isFull = 0;

    // Initialize buffer with zeros (optional)
    for (int i = 0; i < BUFFER_SIZE; i++) {
        cb->buffer[i] = 0;
    }
}

// Function to insert a new value into the buffer
void insertSample(CircularBuffer *cb, int value) {
    // Store value at head position
    cb->buffer[cb->head] = value;

    // Move head to next position (circular)
    cb->head = (cb->head + 1) % BUFFER_SIZE;

    // If buffer was full, tail needs to move as well
    if (cb->isFull) {
        cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    }

    // Update count
    if (!cb->isFull) {
        cb->count++;
        // Check if buffer becomes full
        if (cb->count == BUFFER_SIZE) {
            cb->isFull = 1;
        }
    }
}

// Function to print all samples in chronological order (oldest to newest)
void printSamples(CircularBuffer *cb) {
    if (cb->count == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    printf("Buffer contents (oldest → newest): ");

    if (!cb->isFull) {
        // Buffer not full - print from tail to head-1
        int index = cb->tail;
        for (int i = 0; i < cb->count; i++) {
            printf("%d ", cb->buffer[index]);
            index = (index + 1) % BUFFER_SIZE;
        }
    } else {
        // Buffer is full - print from tail to tail-1 (wrapping around)
        int index = cb->tail;
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%d ", cb->buffer[index]);
            index = (index + 1) % BUFFER_SIZE;
        }
    }
    printf("\n");
}

// Alternative simpler implementation using a fixed array
void simpleCircularBufferDemo() {
    int buffer[BUFFER_SIZE];
    int nextIndex = 0;
    int isBufferFull = 0;
    int count = 0;

    printf("\n=== Simple Circular Buffer Demo ===\n");

    // Simulate data entry
    int testData[] = {10, 12, 14, 15, 13, 18, 20};
    int testSize = sizeof(testData) / sizeof(testData[0]);

    for (int i = 0; i < testSize; i++) {
        // Store data
        buffer[nextIndex] = testData[i];

        // Update next index (circular)
        nextIndex = (nextIndex + 1) % BUFFER_SIZE;

        // Update count
        if (!isBufferFull) {
            count++;
            if (count == BUFFER_SIZE) {
                isBufferFull = 1;
            }
        }

        // Print current state
        printf("Added %d: ", testData[i]);
        if (!isBufferFull) {
            for (int j = 0; j < count; j++) {
                printf("%d ", buffer[j]);
            }
        } else {
            // Print from nextIndex (oldest) to nextIndex-1
            for (int j = 0; j < BUFFER_SIZE; j++) {
                int idx = (nextIndex + j) % BUFFER_SIZE;
                printf("%d ", buffer[idx]);
            }
        }
        printf("\n");
    }
}

int main() {
    CircularBuffer cb;
    int choice, value;

    // Initialize buffer
    initBuffer(&cb);

    printf("=== Circular Data Logger ===\n");
    printf("Buffer size: %d\n", BUFFER_SIZE);
    printf("Commands:\n");
    printf("  1 - Insert sample\n");
    printf("  2 - Print buffer contents\n");
    printf("  3 - Run example workflow\n");
    printf("  0 - Exit\n");

    while (1) {
        printf("\nEnter command: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting program.\n");
                return 0;

            case 1:
                printf("Enter sensor value: ");
                scanf("%d", &value);
                insertSample(&cb, value);
                printf("Inserted %d\n", value);
                break;

            case 2:
                printSamples(&cb);
                break;

            case 3:
                printf("\n=== Running Example Workflow ===\n");
                printf("Initial buffer state: ");
                printSamples(&cb);

                // Example: Insert 10, 12, 14, 15, 13
                int example1[] = {10, 12, 14, 15, 13};
                printf("\nInserting: 10 12 14 15 13\n");
                for (int i = 0; i < 5; i++) {
                    insertSample(&cb, example1[i]);
                }
                printf("Buffer after 5 inserts: ");
                printSamples(&cb);

                // Insert 18 (overwrites oldest 10)
                printf("\nInserting: 18\n");
                insertSample(&cb, 18);
                printf("Buffer after inserting 18: ");
                printSamples(&cb);

                // Insert 20 (overwrites oldest 12)
                printf("\nInserting: 20\n");
                insertSample(&cb, 20);
                printf("Buffer after inserting 20: ");
                printSamples(&cb);
                break;

            default:
                printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}
