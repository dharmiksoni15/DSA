#include <stdio.h>

int main() {
    int arr[] = {4, 1, 5, 2, 3}; // Input array
    int n = 5;

    int i, curr, prev;

    // Outer loop: start from second element
    for (i = 1; i < n; i++) {

        curr = arr[i];   // Current element to insert
        prev = i - 1;    // Index of previous element

        // Shift elements that are greater than curr
        // Move them one position ahead
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev]; // Shift right
            prev--;                    // Move left
        }

        // Place curr at correct position
        arr[prev + 1] = curr;
    }

    // Print sorted array
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}