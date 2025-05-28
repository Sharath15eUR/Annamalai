#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int matrix[][100], int n, int key) {
    int row = 0, col = n - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == key)
            return true;
        else if (matrix[row][col] > key)
            col--;
        else
            row++;
    }

    return false;
}

// Test the function
int main() {
    int matrix[100][100] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int n = 4;
    int key = 29;

    if (searchMatrix(matrix, n, key))
        printf("Key %d found in matrix.\n", key);
    else
        printf("Key %d not found in matrix.\n", key);

    return 0;
}
