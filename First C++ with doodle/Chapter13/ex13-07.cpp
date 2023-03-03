#include <iostream>
using namespace std;


int fact(int n) {

    if (n < 1) {
        throw to_string(n) + " : �ڿ����� �ƴմϴ�.";
    }
    if (n == 1) {
        return 1;
    }

    return n * fact(n-1);

}

int comb(int n, int r) {
    int a = fact(n);
    int b = fact(r);
    int c = fact(n-r);

    return  a / b / c ;
}

int main() {

    int n, r;
    
    try {
        while (true) {
            cout << "�ڿ����� 2�� �Է� �ϼ��� : ";
            cin >> n >> r;
            cout << comb(n, r) << endl;
        }
        
    }
    catch (const string &e) {
        cout << e << endl;
    }

}