#include <stdio.h>
#include <stdlib.h>

void rearrangeEvenOdd(int* arr, int size) {
    int* temp = (int*)malloc(size * sizeof(int));
    int* tempPtr = temp;

    // Step 1: Copy even numbers preserving order
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            *tempPtr = *(arr + i);
            tempPtr++;
        }
    }

    // Step 2: Copy odd numbers preserving order
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 != 0) {
            *tempPtr = *(arr + i);
            tempPtr++;
        }
    }

    // Step 3: Copy back to original array
    for (int i = 0; i < size; i++) {
        *(arr + i) = *(temp + i);
    }

    free(temp);
}

// Test the function
int main() {
    int arr[] = {3, 2, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    rearrangeEvenOdd(arr, size);

    printf("Rearranged array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    return 0;
}
