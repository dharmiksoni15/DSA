#include <stdio.h>

int main() {
    int arr[] = {4, 1, 5, 2, 3}; // input array
    int n = 5;
    int i, j, temp;

    // Outer loop (passes)
    for (i = 0; i < n - 1; i++) {

        // Inner loop (comparison)
        for (j = 0; j < n - i - 1; j++) {

            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {

                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}