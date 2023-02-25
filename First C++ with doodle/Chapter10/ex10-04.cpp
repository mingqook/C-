#include <iostream>
using namespace std;

namespace minguk {
    int n;
    void set() {
        n = 20;
    }
}


int main() {

    using namespace minguk;

    set();
    cout << n << endl;

}