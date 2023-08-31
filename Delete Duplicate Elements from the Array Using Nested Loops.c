//Delete Duplicate Elements from the Array Using Nested Loops
// Include Header Files
#include<stdio.h>
#include<stdlib.h>

// Define Main function
int main(){

   // Declare int variables and arrays
   int array[25], i, j, k, size;
   
   // Ask user for array size
   printf("Enter the size of the array\n");
   scanf("%d",&size);
   
   // Ask user for elements in the array
   printf("Enter Elements of the array:\n");
   
   // Use for loop to insert each element into the array
   for(i=0;i<size;i++){
      scanf("%d",&array[i]);
   }
   
   // Print the entire array including duplicate one
   printf("Original Array:- \n");
   for(i=0;i<size;i++){
      printf("%d" ,array[i]);
   }
   
   // Remove duplicate using nested for loops
   for(i=0;i<size;i++){
      
      // For each index iteration search in the rest of the array for its duplicates.
      for(j = i+1; j < size; j++){
          
         // If duplicates found using if condition
         if(array[i] == array[j]){
             
            // Shift all elements by 1 if duplicates are found.
            for(k = j; k < size; k++){
               array[k] = array[k+1];
            }

            // Move j again to the previous position 
            j--;
            
            // Reduce the size of the Array by 1
            size--;
         }
      }
   }
   
   // Print the array once deleting all duplicates
   printf("\nNew Array :-\n");
   for(i=0;i<size;i++){
      printf("%d ",array[i]);
   }
}
