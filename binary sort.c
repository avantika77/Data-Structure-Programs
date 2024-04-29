#include<stdio.h> // Include necessary header files
#include<stdlib.h>

// Define the structure for a Node
struct Node { //node creation
    int data;
    struct Node* left; //pointer
    struct Node* right; 
};

// Define an alias for struct Node as Node
typedef struct Node Node; // another name ( node) so don't need to write struct structure everytime
//---------------------------------------------------------------------------------------- 

// Function to create a new node with the given value
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = value; //value 
    newNode->left = newNode->right = NULL; // Initialize left and right pointers to NULL
    return newNode;
}

// Function to recursively insert a node into the BST
Node* insertRecursiveNode(Node* root, int value) {
    if (root == NULL) // If root is NULL, create a new node 
        return createNode(value); //root and its value
    if (value < root->data)
        root->left = insertRecursiveNode(root->left, value); // Recur for left subtree //smallest value
    else if (value > root->data)
        root->right = insertRecursiveNode(root->right, value); // Recur for right subtree //largest value+3


    return root;
}

// Function to find the minimum value node in a subtree
Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to recursively delete a node from the BST
Node* deleteRecursiveNode(Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = deleteRecursiveNode(root->left, value);
    else if (value > root->data)
        root->right = deleteRecursiveNode(root->right, value);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteRecursiveNode(root->right, temp->data);
    }
    return root;
}

// Function to perform in-order traversal recursively
void inOrderRecursive(Node* root) {
    if (root != NULL) {
        inOrderRecursive(root->left);
        printf("%d ", root->data);
        inOrderRecursive(root->right);
    }
}

// Function to perform pre-order traversal recursively
void preOrderRecursive(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
}

// Function to perform post-order traversal recursively
void postOrderRecursive(Node* root) {
    if (root != NULL) {
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// Define the structure for Binary Search Tree (BST)
typedef struct BST {  // alias 
    Node* root;
} BST;

// Function to create a new empty BST
BST* createBST() {
    BST* tree = (BST*) malloc(sizeof(BST));
    tree->root = NULL; // Initialize root to NULL
    return tree;
}

// Function to insert a value into the BST
void insert(BST* tree, int value) {
    tree->root = insertRecursiveNode(tree->root, value);
}

// Function to remove a node with the given value from the BST
void removeNode(BST* tree, int value) {
    tree->root = deleteRecursiveNode(tree->root, value);
}

// Function to search for a value in the BST
int search(BST* tree, int value) {
    Node* current = tree->root;
    while (current != NULL) {
        if (value == current->data)
            return 1; // Value found
        else if (value < current->data)
            current = current->left; // Move to left subtree
        else
            current = current->right; // Move to right subtree
    }
    return 0; // Value not found
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(BST* tree) {
    printf("In-order traversal: ");
    inOrderRecursive(tree->root);
    printf("\n");
}

// Function to perform pre-order traversal of the BST
void preOrderTraversal(BST* tree) {
    printf("Pre-order traversal: ");
    preOrderRecursive(tree->root);
    printf("\n");
}

// Function to perform post-order traversal of the BST
void postOrderTraversal(BST* tree) {
    printf("Post-order traversal: ");
    postOrderRecursive(tree->root);
    printf("\n");
}

// Main function
int main() {
    BST* tree = createBST(); // Create an empty BST
    int choice, value;

    // Menu-driven program
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Search\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(tree, value);
                printf("Value %d inserted.\n", value);
                break;
            case 2:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                removeNode(tree, value);
                printf("Value %d removed.\n", value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(tree, value))
                    printf("Value %d found.\n", value);
                else
                    printf("Value %d not found.\n", value);
                break;
            case 4:
                inOrderTraversal(tree);
                break;
            case 5:
                preOrderTraversal(tree);
                break;
            case 6:
                postOrderTraversal(tree);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
