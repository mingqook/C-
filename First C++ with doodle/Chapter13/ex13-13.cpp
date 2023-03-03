#include <iostream>
#include <memory>
using namespace std;


class MyClass {
    public:
        MyClass(int x) : x(x) {
            cout << "MyClass(int)" << endl;
        }
        ~MyClass() {
            cout << "~MyClass()" << endl;
        }
        int GetX() const {
            return x;
        }
    private:
        int x;
};


int main() {

    unique_ptr<MyClass> a(new MyClass(5));
    cout << a->GetX() << endl;
    cout << "===== 1 =====" << endl;
    a.reset(new MyClass(7));

    cout << a->GetX() << endl;
    cout << "===== 2 =====" << endl;
    a.reset();

    cout << "===== 3 =====" << endl;
    a.reset(new MyClass(9));

    cout << "===== 4 =====" << endl;

}