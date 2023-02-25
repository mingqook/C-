#include <iostream>
using namespace std;

class MyClass {
    public:
        MyClass() {
            cout << "생성자가 호출 되었다!!" << endl;
        }
        ~MyClass() {
            cout << "소멸자가 호출되었다!!" << endl;
        }
};

MyClass globalObj;

void testLocalObj() {
    cout << "=== testLocalObj 함수 시작 ===" << endl;
    // MyClass localObj;
    cout << "=== testLocalObj 함수 끝 ===" << endl;
}

int main() {
    cout << "=== main 함수 시작 ===" << endl;
    testLocalObj();
    cout << "=== main 함수 끝 ===" << endl;
}