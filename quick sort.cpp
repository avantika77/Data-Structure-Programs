#include <iostream>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1; // Return the partition index
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int MAX_SIZE = 5; // Maximum size of the array
    int arr[MAX_SIZE];
    int numElements = 0;

    std::cout << "Enter the array elements (enter a non-numeric value to stop):\n";
    while (std::cin >> arr[numElements]) {
        numElements++;
        if (numElements >= MAX_SIZE) {
            std::cout << "Maximum number of elements reached.\n";
            break;
        }
    }

    std::cout << "Original array: ";
    for (int i = 0; i < numElements; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, numElements - 1); // Perform Quick Sort

    std::cout << "Sorted array: ";
    for (int i = 0; i < numElements; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
