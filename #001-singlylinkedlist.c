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
