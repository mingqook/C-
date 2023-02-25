#include <iostream>
using namespace std;

/************** Ŭ���� ���� *******************/
class Vector2 {
    public:
        Vector2();
        Vector2(float x, float y);
        float GetX() const;
        float GetY() const;
        Vector2 operator+(Vector2 other);
        Vector2 operator-(Vector2 other);
    private:
        float x, y;
}


/************** main �Լ� *******************/

int main() {
    Vector2 a(2,3), b(5,6);
    Vector2 c1 = a+b;
    Vector2 c2 = a-b;

    cout << "c1 = ( " << c1.GetX() << ", " << c1.GetY() << " )" << endl;
    cout << "c2 = ( " << c2.GetX() << ", " << c2.GetY() << " )" << endl;
    cout << "c3 = ( " << c3.GetX() << ", " << c3.GetY() << " )" << endl;
}

/************** �Լ� ���� *******************/
Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x;}
float Vector2::GetY() const { return y;}
Vector2 Vector2::operator+(Vector2 other) {
    return Vector2(x + other.x, y+other.y);
}
Vector2 Vector2::operator-(Vector2 other) {
    return Vector2(x - other.x, y-other.y);
}
