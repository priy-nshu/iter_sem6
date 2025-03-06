#include<iostream>
using namespace std;

class area {
private:
    void rec(float l, float b) {
        cout << "Area of rectangle: " << (l * b) << endl;
    }

    void sq(float a) {
        cout << "Area of square: " << (a * a) << endl;
    }

public:
    friend int main();
};

int main() {
    area x;
    x.rec(10, 20);  
    x.sq(6.9);  

    return 0;
}

