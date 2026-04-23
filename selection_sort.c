#include <stdio.h>   // Library for input and output functions

int main() {         // Entry point of the program

    int arr[] = {64, 25, 12, 22, 11};  // Array to be sorted
    int n = 5;                         // Number of elements in array

    // Outer loop: controls number of passes
    for(int i = 0; i < n - 1; i++) {

        int minIndex = i;  // Assume current index has the minimum value

        // Inner loop: find the smallest element in remaining array
        for(int j = i + 1; j < n; j++) {

            // Compare current element with current minimum
            if(arr[j] < arr[minIndex]) {
                minIndex = j;  // Update index of smallest element
            }
        }

        // Swap the found minimum element with first unsorted element
        int temp = arr[i];           // Store current element
        arr[i] = arr[minIndex];      // Place minimum element at correct position
        arr[minIndex] = temp;        // Put stored value at minIndex
    }

    printf("Sorted array: ");  // Print message

    // Loop to print sorted array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Print each element
    }

    return 0;  // End of program
}