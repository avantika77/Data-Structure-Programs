//simple program of pointer to mannipulate the variables in the program
#include<stdio.h>
int main()
{
    int a=97;
    int *ptr;
    ptr=&a;//assigning the address of variable a in ptr "&" assign address
    printf("Value of a is %d\n", a);
    printf("Value through ptr %d\n", a);
    *ptr=89; //changed value
    printf("Value after change %d\n", a);
}