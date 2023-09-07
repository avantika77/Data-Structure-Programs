// array as parameter
#include <stdio.h>
//function to print array
void array(int arr[],int size)
{
    for (int i = 0; i < size;i++)
    {
    printf("%d ",arr[i]);
    }  //till here 
printf("\n");
} // for next line
//main function 
int main(){
    int numbers[]={12,465,656,5}; //array number 
    int size=sizeof(numbers)/ sizeof(numbers[0]);//size calculation in tern of array name (here, number)
    printf("original array:");
    array(numbers,size);//passing array to the function
    return 0;

}