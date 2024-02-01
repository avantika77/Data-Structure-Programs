#include <iostream>

class Person {
    // parent class
public:
    std::string name;
    int age;

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Employee : public Person {
    // child class
public:
    std::string job_title;  // corrected: removed space in variable name

    void displayEmployee() const {
        display(); // inheritance: calling function from the parent class
        std::cout << "Job Title: " << job_title << std::endl;
    }
};

int main() {
    Employee employee;
    employee.name = "John";
    employee.age = 30;
    employee.job_title = "Software Engineer";

    employee.displayEmployee();  // corrected: removed space in function call

    return 0;
}
