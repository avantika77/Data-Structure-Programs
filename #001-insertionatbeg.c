#include <stdio.h> //header files
#include <stdlib.h>

//  structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the beginning of the linked list
struct Node *insertAtBeginning(struct Node *head, int data) // node need head to get data
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = data;                                              // Assign data to the new node
    newNode->next = head;                                              // Make the new node point to the current head
    return newNode;                                                    // Set the new node as the new head of the list
}
// current
// Function to display the linked list
void display(struct Node *head)
{
    struct Node *current = head; // pointer named "current" and sets it equal to the value of the "head" pointer
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL; // Initialize an empty linked list

    int data;

    printf("Enter data to insert at the beginning (enter -1 to stop):\n"); // this to insert data at beg as much as u want

    while (1)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        if (data == -1)
        {
            break; // Exit the loop if -1 is entered
        }

        head = insertAtBeginning(head, data); // Insert the data at the beginning
    }

    printf("Linked List after insertions: ");
    display(head);

    return 0;
}
