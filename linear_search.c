#include <stdio.h>

int main() {
    int arr[100], n, key, i;
    int found = 0;   // Flag variable to check whether element is found or not

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear search starts here
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;   // Element found
            printf("Element found at position %d\n", i + 1);
            break;       // Stop searching after finding the element
        }
    }

    // If element was not found in the array
    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}