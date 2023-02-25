#include <iostream>
using namespace std;

/************** 클래스 정의 *******************/
class Vector2 {
    public:
        Vector2();
        Vector2(float x, float y);
        float GetX() const;
        float GetY() const;
        static Vector2 Sum(Vector2 a, Vector2 b);
        Vector2 Add(Vector2 other);
    private:
        float x, y;
}

Vector2 Sum(Vector2 a, Vector2 b);

/************** main 함수 *******************/

int main() {
    Vector2 a(2,3), b(5,6);
    Vector2 c1 = Sum(a, b);
    Vector2 c2 = Vector2::Sum(a, b);
    Vector2 c3 = a.Add(b);

    cout << "c1 = ( " << c1.GetX() << ", " << c1.GetY() << " )" << endl;
    cout << "c2 = ( " << c2.GetX() << ", " << c2.GetY() << " )" << endl;
    cout << "c3 = ( " << c3.GetX() << ", " << c3.GetY() << " )" << endl;
}

/************** 함수 정의 *******************/
Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x;}
float Vector2::GetY() const { return y;}
Vector2 Vector2::Sum(Vector2 a, Vector2 b) {
    return Vector2(a.x + b.x, a.y+b.y);
}
Vector2 Vector2::Add(Vector2 other) {
    return Vector2(x + other.x, y+other.y);
}
Vector2 Sum(Vector2 a, Vector2 b) {
    return Vector2(a.GetX()+b.GetX(), a.GetY()+b.GetY());
}