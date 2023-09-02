//C Program to Count Frequency of Each Element in an Array
#include <stdio.h>    
    
int main()    
{      
    printf("Coding Ninjas\n");
    int array_input[] = {1, 2, 9, 3, 8, 2, 5, 2, 1};     
        
    int length = sizeof(array_input)/sizeof(array_input[0]);    
        
    int frequency [length];    
    int visited = -1;    
        
    for(int i = 0; i < length; i++){    
        int count_var = 1;    
        for(int j = i+1; j < length; j++){    
            if(array_input[i] == array_input[j]){    
                count_var++;     
                frequency [j] = visited;    
            }    
        }    
        if(frequency [i] != visited)    
            frequency [i] = count_var;    
    }    
        
    printf("---------------------\n");    
    printf(" Element | frequency of element\n");    
    printf("---------------------\n");    
    for(int i = 0; i < length; i++){    
        if(frequency [i] != visited){    
            printf("    %d", array_input[i]);    
            printf("    |  ");    
            printf("  %d\n", frequency [i]);    
        }    
    }
        
    printf("---------------------\n");    
    return 0;    
}   
