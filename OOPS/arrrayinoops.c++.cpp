#include <iostream>
#include <sstream>
using namespace std;

// Function to double an integer
int doubleNumber(int num)
{
    return num * 2;
}

int main()
{
    
    // Stream-based I/O
    // Reading user input as string
    std::string userInput;
    std::cout << "Enter an integer: ";
    std::cin >> userInput;

    // Converting string into int
    int convertedNumber;
    std::stringstream(userInput) >> convertedNumber;

    // Display the converted integer
    std::cout << "You entered: " << convertedNumber << std::endl;

    // Topic array
    // Creating and processing array
    int MyArray[] = {1, 2, 3, 4, 5};

    // Process array elements without a for loop
    MyArray[0] = doubleNumber(MyArray[0]);
    MyArray[1] = doubleNumber(MyArray[1]);
    MyArray[2] = doubleNumber(MyArray[2]);
    MyArray[3] = doubleNumber(MyArray[3]);
    MyArray[4] = doubleNumber(MyArray[4]);

    // Display processing array
    std::cout << "Processed array: " << MyArray[0] << ", " << MyArray[1] << ", " << MyArray[2] << ", " << MyArray[3] << ","<< MyArray[4] <<","<< std::endl;

    return 0;
}
