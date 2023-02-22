#include <iostream>
using namespace std;

void f(int a=1){
    cout << a << endl;
}

int main() {

    f(123);
    f();
}