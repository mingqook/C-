#include <iostream>
using namespace std;

namespace minguk {
    int n, m;
    void set();
    namespace qook {
        int n;
        void set();
    }
}

void minguk::set() {
    n = 20;
}

void minguk::qook::set() {
    m = 30;
    n = 40;
}

int main() {

    minguk::set();
    minguk::qook::set();
    
    cout << minguk::m << endl;
    cout << minguk::n << endl;
    cout << minguk::qook::n << endl;

}