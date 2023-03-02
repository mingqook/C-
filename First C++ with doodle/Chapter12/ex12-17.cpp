#include <iostream>

using namespace std;


struct Mom {
    int a = 1;
};

struct Dad {
    int b = 2;
};

struct Child : Mom, Dad {
    int c = 3;
};

int main() {

   Child ch;

   cout << ch.a << endl;
   cout << ch.b << endl;
   cout << ch.c << endl;

}