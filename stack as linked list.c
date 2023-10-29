#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed onto the stack\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->top->data;
}

void displayStack(struct Stack* stack) {
    struct Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = initializeStack();
    int choice, value, count;

    while (1) {
        printf("*********** MENU *************\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements to push: ");
                scanf("%d", &count);
                for (int i = 0; i < count; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &value);
                    push(stack, value);
                }
                break;

            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;

            case 3:
                value = peek(stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;

            case 4:
                displayStack(stack);
                break;

            case 5:
                exit(0);

            default:
                printf("Please select a valid option!\n");
        }
    }

    return 0;
}
