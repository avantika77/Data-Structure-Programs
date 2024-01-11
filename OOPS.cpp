//abstarction=Abstraction involves displaying only essential information while concealing underlying details.
//Data abstraction refers to providing only data-related information to the user, hiding additional information that is not needed.
#include<iostream>
using namespace std;
class abstraction
{
    private:
    int a,b;
    
    public:
    void set (int x ,int y)
    {
        a=x;
        b=y;
    }

    void display()
    {
        cout << "a ="<< a <<endl;
        cout << "b ="<< b <<endl;
    }
};
int main()
{
    abstraction obj;
    obj.set(10,20);
    obj.display();
    return 0;   
}