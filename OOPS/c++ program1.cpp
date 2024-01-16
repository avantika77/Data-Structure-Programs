#include <iostream>
using namespace std;
int main()
{
    std::cout << "hello world " << endl;
    std::cout << " Airthmetic Operations :" << endl;
    // enter age
    int age;
    cout << "enter your age." << endl;
    cin >> age;
    cout << "your age is " << age << endl;
    // add two number
    int a, b;
    cout << "Add two numbers:" << endl;
    cout << "enter value of a:" << endl;
    cin >> a;
    cout << "Enter value of b:" << endl;
    cin >> b;
    cout << "sum is " << a + b << endl;
    cout << "---------------------------------------------"<< endl;

    // substraction
    cout << "subtractions:" << endl;
    cout << "subtaction is :" << a - b << endl;
    cout << "---------------------------------------------"
    << endl;

    // division
    cout << "division :" << endl;
    cout << "division is :" << a / b << endl;
    cout << "---------------------------------------------" << endl;
    // multiplication
    cout << "multiplication :" << endl;
    cout << "multiplication is :" << a * b << endl;
    cout << "Completed" << endl;
}