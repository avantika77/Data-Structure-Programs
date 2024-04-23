#include <iostream>

class Widget {
public:
    Widget(int id) : widgetId(id) {}
    void showId() const {
        std::cout << "Widget ID: " << widgetId << std::endl;
    }

private:
    int widgetId;
};

class Button : virtual public Widget {
public:
    Button(int id) : Widget(id) {}
};

class Checkbox : virtual public Widget {
public:
    Checkbox(int id) : Widget(id) {}
};


int main() {
    Checkbox Checkbox(1001);
    Checkbox.showId();  // Outputs the unique Widget ID
    return 0;
}
