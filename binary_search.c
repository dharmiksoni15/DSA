#include <stdio.h>

int main() {
    int arr[100], n, key;
    int low, high, mid, i;
    int found = 0;   // Flag variable to check if element is found

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input sorted array elements
    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Initialize low and high
    low = 0;
    high = n - 1;

    // Binary search starts
    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            found = 1;
            printf("Element found at position %d\n", mid + 1);
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;   // Search in right half
        }
        else {
            high = mid - 1;  // Search in left half
        }
    }

    // If element is not found
    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}