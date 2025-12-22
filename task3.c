
#include <stdio.h>

int main() {
    int count = 10;
    int *pCount = &count;

    *pCount = 20;   // modify using pointer

    printf("Updated value of count: %d\n", count);
    return 0;
}
