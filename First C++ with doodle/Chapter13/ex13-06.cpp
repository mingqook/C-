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

int main() {

    int n, r;
    
    try {
        cout << "�ڿ����� 2�� �Է� �ϼ��� : ";
        cin >> n >> r;

        int a = fact(n);
        int b = fact(r);
        int c = fact(n-r);

        int result = a / b / c ;
        cout << result << endl;
        
    }
    catch (const string &e) {
        cout << e << endl;
    }

}