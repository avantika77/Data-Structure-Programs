
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
    printf("Insertion success!!!\n");
}

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Insertion success!!!\n");
}

void insertAtAfter(int value, int location) {
    if (head == NULL) {
        printf("List is empty. Insertion after a node is not possible.\n");
        return;
    } else {
        struct Node *temp = head;
        do {
            if (temp->data == location) {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                printf("Insertion success!!!\n");
                return;
            }
            temp = temp->next;
        } while (temp != head);
        printf("Node with the specified value was not found in the list.\n");
    }
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Deletion from the beginning is not possible.\n");
        return;
    } else {
        struct Node *temp = head;
        if (temp->next == head) {
            head = NULL;
            free(temp);
        } else {
            struct Node *lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            head = head->next;
            lastNode->next = head;
            free(temp);
        }
        printf("Deletion success!!!\n");
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Deletion from the end is not possible.\n");
        return;
    } else {
        struct Node *temp = head, prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = NULL;
        } else {
            prev->next = head;
        }
        free(temp);
        printf("Deletion success!!!\n");
    }
}

void deleteSpecific(int delValue) {
    if (head == NULL) {
        printf("List is empty. Deletion of a specific node is not possible.\n");
        return;
    } else {
        struct Node *temp = head, prev = NULL;
        int found = 0;

        do {
            if (temp->data == delValue) {
                found = 1;
                if (temp == head) {
                    struct Node *lastNode = head;
                    while (lastNode->next != head) {
                        lastNode = lastNode->next;
                    }
                    head = head->next;
                    lastNode->next = head;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
                printf("Deletion success!!!\n");
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            printf("Node with the specified value was not found in the list.\n");
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node *temp = head;
        do {
            printf("%d ---> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    int choice1, choice2, value, location;

    while (1) {
        printf("\n*********** MENU *************\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                while (1) {
                    printf("\nSelect from the following Inserting options\n");
                    printf("1. At Beginning\n2. At End\n3. After a Node\n4. Cancel\nEnter your choice: ");
                    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1:
                            insertAtBeginning(value);
                            break;
                        case 2:
                            insertAtEnd(value);
                            break;
                        case 3:
                            printf("Enter the value after which you want to insert: ");
                            scanf("%d", &location);
                            insertAtAfter(value, location);
                            break;
                        case 4:
                            goto EndSwitch;
                        default:
                            printf("\nPlease select correct Inserting option!!!\n");
                    }
                }

            case 2:
                while (1) {
                    printf("\nSelect from the following Deleting options\n");
                    printf("1. At Beginning\n2. At End\n3. Specific Node\n4. Cancel\nEnter your choice: ");
                    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1:
                            deleteBeginning();
                            break;
                        case 2:
                            deleteEnd();
                            break;
                        case 3:
                            printf("Enter the Node value to be deleted: ");
                            scanf("%d", &location);
                            deleteSpecific(location);
                            break;
                        case 4:
                            goto EndSwitch;
                        default:
                            printf("\nPlease select correct Deleting option!!!\n");
                    }
                }
                EndSwitch: 
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nPlease select a correct option!!!\n");
        }
    }
    return 0;
}