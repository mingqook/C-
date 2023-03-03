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
    cout << "자연수를 입력 하세요 : ";
    cin >> n;

    if (n > =1) {
        cout << n << "! = " << fact(n) << endl;
    }

    else {
        cout << n << " : 자연수가 아닙니다." << endl;
    }

}