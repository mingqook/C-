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
        n = 30;
    }
}

int main() {

    minguk::set();
    qook::set();

    cout << minguk::n << endl;
    cout << qook::n << endl;

}