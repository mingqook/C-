#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    string greeting;

    cout << "�̸� �Է� : ";
    cin >> name;

    greeting = "�ȳ��ϼ���, " + name + " ��!";
    
    cout << greeting << endl;
    cout << name << "�� �� " << name.length() << "�����Դϴ�." << endl;
    cout << name << "�� ù ���ڴ� " << name[0] << "�Դϴ�. " << endl;
}