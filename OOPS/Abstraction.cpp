abstarction =Abstraction involves displaying only essential information while concealing underlying details.
Data abstraction refers to providing only data-related information to the user, hiding additional information that is not needed.
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

abstraction using header file
#include <iostream>
#include <math.h>
using namespace std;
int main()
{

    int n = 8;
    int power = 5;
    int result = pow(n, power);
    std::cout << "Cube is:" << result << std::endl;
    return 0;
}

//abstraction  using class
#include <iostream>
using namespace std;
class Sum{
    private:int x ,y ,z;
    public:
    void add(){
        cout << "enter two values" << std::endl;
        cin >> x >> y;
        z=x+y;
        cout<<"sum of two numbers: " <<z<< std::endl;

    }errc
};
int main()    
{    
Sum sm;    
sm.add();    
return 0;    
}    






    