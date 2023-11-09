//Linear Search
// #include <iostream>
// using namespace std;
 
// int search(int array[], int n, int x)
// {
 
//     // Going through array sequencially
//     for (int i = 0; i < n; i++)
//         if (array[i] == x)
//             return i;
//     return -1;
// }
 
// int main()
// {
//     int array[] = { 12, 114, 0, 4, 9 };
//     int x = 4;
//     int n = sizeof(array) / sizeof(array[0]);
 
//     int result = search(array, n, x);
 
//     (result == -1)
//         ? cout << "Element not found"
//         : cout << "Element found at index: " << result;
// }
===============================================================================================================================================
 #include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[20], size, i, data;

    printf("enter the size of the list\n");
    scanf("%d", &size);

    printf("enter the number of elements in the list\n");
    for (i = 0; i < size; i++)
        scanf("%d", &list[i]);

    printf("enter the number of element you want to search in the list: ");
    scanf("%d", &data);

    for (i = 0; i < size; i++)
    {
        if (data == list[i])
        {
            printf("element found in the list at index %d\n", i);
            break;  // Add a break to exit the loop once the element is found
        }
    }

    if (i == size)
    {
        printf("element not found in the list\n");
    }
}

