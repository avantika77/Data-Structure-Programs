#include <stdio.h>
#include <stdlib.h>

struct Node // node construction
{
    int data;
    struct Node *next;
};
// traversing list------------------------------------------------------------------------------------------------------------
void tarversinglist(struct Node *ptr) // traversing function
{
    while (ptr != NULL)
    {
        printf("Element of nodes: %d\n", ptr->data); // printing node data
        ptr = ptr->next;                             // pointer prt to next node
    }
}

//inserting at beginning----------------------------------------------------------------------------------------------------

struct Node *insertatbeg(struct Node *head, int data)
// sruct node*= an mew node ;
// where insertatbeg
// what it should have= struct Node *head, int data;
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head; // new ptr =head which is already existed
    ptr->data = data; // new ptr data =97
    return ptr;
}
int main()

{ // nodes creation
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // first node
    head->data = 7;
    head->next = second; // link to second node

    // second node
    second->data = 17;
    second->next = third; // link to third

    // Link third and fourth nodes
    third->data = 777;
    third->next = fourth;

    // fourth node
    fourth->data = 7777;
    fourth->next = NULL;
    
    tarversinglist(head); // function calling
    printf("\n");
    head = insertatbeg(head, 97);//insertion at beginning of list
    tarversinglist(head);
    return 0;
}