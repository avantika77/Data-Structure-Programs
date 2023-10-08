#include<stdio.h>
 #include<stdlib.h>
 struct Node{
 int data;
 struct Node *next;
 };
 struct Node *head;
 void insert(int x){
 struct Node *link = (struct Node*)malloc(sizeof(struct Node));
 link->data = x;
 link->next = head;
 head = link;
 }
 void disp(){
 struct Node *prt = head;
 printf("List is : \n");
 while(prt!=NULL){
 printf(" %d",prt->data);
 prt = prt->next;
 }
 printf("\n");
 }
 
 int main(){
 insert(10);
 insert(20);
 insert(30);
 disp();
 return 0;
 }
#OUTPUT#----------------------------------------------------------------------------
List is : 
 30 20 10

 -----------------------------------------------------------------------------------------------------------------
 -----------------------------------------------------------------------------------------------------------------
 #include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Creation of the first node
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    // Creation of the second node
    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;
     // Creation of the third node
    current = malloc(sizeof(struct node));
    current->data = 6;
    current->link = NULL;
    head->link->link = current;
    // Printing all elements
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d , ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    return 0;
}
