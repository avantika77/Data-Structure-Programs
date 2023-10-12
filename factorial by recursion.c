#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 and 1 is 1
    } else {
        return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
    }
}

int main() {
    int num;

    // Prompt the user to enter a non-negative integer
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is undefined for negative numbers.\n");
    } else {
        // Calculate and print the factorial
         int result = factorial(num);
        printf("Factorial of %d is %d\n", num, result);
    }

    return 0;
}
