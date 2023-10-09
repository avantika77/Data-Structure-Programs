
#include <stdio.h>

// Function to calculate the nth Fibonacci number using recursion
long long int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, i;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%lld", fibonacci(i));
        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("\n");
    return 0;
}
#OUTPUT-----------------------------------------------------------------------------------------
Enter the number of terms in the Fibonacci series: 8
Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13
