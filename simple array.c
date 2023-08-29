//simple array program 
#include <stdio.h> // header file
int main() {
    // size of array from user 
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int numbers[size]; //size variable length

    // Initialize the array elements using user input
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    } // all user input will allocate in array according to size

    // Calculate the sum of array elements of array
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
     // Display results - one of the operation in array "displaying"
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Sum of array elements: %d\n", sum);
   

    return 0;
}
