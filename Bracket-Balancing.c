#include <stdio.h>

// Stack implemented using array
char stack[100];
int top = -1;   // Initially stack is empty

int main() {
    char str[100];
    int i = 0;

    // Take input from user
    printf("Enter brackets: ");
    scanf("%s", str);

    // Traverse the string character by character
    while (str[i] != '\0') {

        // 🔹 CASE 1: If opening bracket is found
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            
            top++;                   // Increment top
            stack[top] = str[i];     // Push element into stack
        }

        // 🔹 CASE 2: If closing bracket is found
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {

            // If stack is empty → no matching opening bracket
            if (top == -1) {
                printf("Not Balanced");
                return 0;
            }

            // Pop the last opening bracket
            char last = stack[top];
            top--;

            //  Check if brackets are matching
            if ((str[i] == ')' && last != '(') ||
                (str[i] == '}' && last != '{') ||
                (str[i] == ']' && last != '[')) {

                printf("Not Balanced");
                return 0;
            }
        }

        i++;   // Move to next character
    }

    // 🔹 FINAL CHECK
    if (top == -1) {
        printf("Balanced");      // All brackets matched
    } else {
        printf("Not Balanced");  // Some opening brackets left
    }

    return 0;
}