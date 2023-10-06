#include <stdio.h> // header file
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the stack here 100
//global declaraton of top and arr[]
int stack_arr[MAX_SIZE];
int top = -1; // Initialize the top of the stack to -1 (empty) //this too global declaration

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int x) {
    if (isFull()) {
        printf("Stack is full. Cannot push.\n");
        exit(1);
    }
    stack_arr[++top] = x;
}// Function to display the stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main() 
{int choice, value, count;
    
    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of values to push: ");
                scanf("%d", &count);
                for (int i = 0; i < count; i++) {
                    printf("Enter a value: ");
                    scanf("%d", &value);
                    push(value);
                }
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

return 0;
}

