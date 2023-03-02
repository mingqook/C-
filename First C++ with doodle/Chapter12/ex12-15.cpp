#include <iostream>
using namespace std;


struct Base {
    int a = 1;
    virtual ~Base() {}
};

struct Drv1 : Base {
    void f() {
        cout << "Drv1::f()" << endl;
        cout << x << endl;
    }
    float x = 3.14;
};

struct Drv2 : Base {
    void f() {
        cout << "Drv2::f()" << endl;
        cout << y << endl;
    }
    int y = 3;
};

int main() {

    Base *b = new Drv1;
    Drv1 *d1 = static_cast<Drv1*>(b);
    Drv2 *d2 = static_cast<Drv2*>(b);

    d1->f();
    d2->f();

    delete b;
}