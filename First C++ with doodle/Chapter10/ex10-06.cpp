#include <iostream>
using namespace std;

class MyClass {
    public:
        void PrintThis() {
            cout << "���� �ּҴ� " << this << endl;
        }
};

int main() {
    
    MyClass a, b;

    cout << "��ü a�� �ּҴ� " << &a << endl;
    cout << "��ü b�� �ּҴ� " << &b << endl;
    
    a.PrintThis();
    b.PrintThis();
}