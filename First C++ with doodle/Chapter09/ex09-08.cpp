#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

int main() {

    int a = 10, b = 20;
    double da = 12.34, db = 56.78;
    char ca = 'A', cb= 'B';

    swap(a,b);
    swap(da, db);
    swap(ca, cb);

    cout << a << " " << b << endl;
    cout << da << " " << db << endl;
    cout << ca << " " << cb << endl;
}