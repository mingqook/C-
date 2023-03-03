#include <iostream>
using namespace std;


int fact(int n) {
    if (n == 1) {
        return 1;
    }

    return n * fact(n-1);

}

int main() {

    int n;
    
    try {
        cout << "자연수를 입력 하세요 : ";
        cin >> n;
        if (n <= 0) {
            throw n;
        }
        cout << n << "! = " << fact(n) << endl;
    }

    catch (int e) {
        cout << e << ": 자연수가 아닙니다." << endl;
    }

}