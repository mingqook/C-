#include <iostream>
using namespace std;

namespace minguk {
    int n;
    void set() {
        n = 20;
    }
}

namespace qook {
    int n;
    void set() {
        minguk::n = 30;
    }
}

int main() {

    minguk::set();
    cout << minguk::n << endl;

    qook::set();
    cout << minguk::n << endl;

}