#include <iostream>
using namespace std;

class MyClass {
private:
    int x;
    int y;

public:
    MyClass() {
        x = 10000;
        y = 20000;
        cout << "Default Constructor called" << endl;
    }
    MyClass(int a, int b) {
        x = a;
        y = b;
        cout << "Parameterized Constructor called" << endl;
    }
    MyClass(MyClass &obj) {
        x = obj.x-1;
        y = obj.y-1;
        cout << "Copy Constructor called" << endl;
    }
    void display() {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    MyClass obj1;
    obj1.display();
    MyClass obj2(5, 10);
    obj2.display();
    MyClass obj3 = obj1;
    obj3.display();

    return 0;
}

