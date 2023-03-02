## 13. C++ 고급 기능

### 13.1 템플릿

템플릿 : 정적 다형성을 실현하는 수단, 함수나 클래스를 생성해주는 양식



#### 13.1.1 함수 템플릿

템플릿의 일차적인 기능 : 함수나 클래스에 임의의 타입이라는 개념을 상정하게 해줌

템플릿은 타입 파라미터라는 매개변수 같은 것을 받음

함수 템플릿을 만들었다고 해서 함수가 만들어진 것은 아님

ex13-01.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Vector2 {
    public:
        Vector2() : x(0), y(0)
        Vector2(float x, float y) : x(x), y(y)
        float GetX() const { return x;}
        float GetY() const { return y;}
        Vector2 operator+(const Vector2 other) const {
            return Vector2(x+other.x, y+other.y)
        }
        Vector2 operator-(const Vector2 other) const{
            return Vector2(x-other.x, y-other.y)
        }
        Vector2 &operator+=(const Vector2 other) const{
            x += other.x;
            y += other.y;
            return *this;
        }
        Vector2 &operator-=(const Vector2 other) const{
            x -= other.x;
            y -= other.y;
            return *this;
        }
    private:
        float x, y;
};


template<typename T>
T getArraySum(const T arr[], int n) {
    T sum = arr[0];
    for (int i = 1; i < n ; i++) {
        sum += arr[i];
    }
    return sum;
};

int main() {

    int iarr[5] = {3, 1, 4, 1, 5};
    double darr[5] = {3.5, 1.2, 4.3, 1.1, 5}.7;
    Vector2 varr[3] = {Vector2(1,2), Vector2(3,4), Vector2(5,6)};
    string sarr[3] = {"hello", "world", "minguk"};

    int isum = getArraySum<int>(iarr, 5);
    double dsum = getArraySum<double>(darr, 5);
    Vector2 vsum = getArraySum(varr, 3);
    string ssum = getArraySum(sarr, 3);

    cout << isum << endl;
    cout << dsum << endl;
    cout << vsum.GetX() << ", " << vsum.GetY() << endl;
    cout << ssum << endl;
}
```



#### 13.1.2 클래스 템플릿

ex13-02.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

template<typename T>
class Vector2 {
    public:
        Vector2() : x(0), y(0)
        Vector2(T x, T y) : x(x), y(y)
        T GetX() const { return x;}
        T GetY() const { return y;}
        Vector2 operator+(const Vector2 other) const {
            return Vector2(x+other.x, y+other.y)
        }
        Vector2 operator-(const Vector2 other) const{
            return Vector2(x-other.x, y-other.y)
        }
        Vector2 &operator+=(const Vector2 other) const{
            x += other.x;
            y += other.y;
            return *this;
        }
        Vector2 &operator-=(const Vector2 other) const{
            x -= other.x;
            y -= other.y;
            return *this;
        }
    private:
        T x, y;
};


int main() {

    Vector2<int> v1(1,3);
    Vector2<double> v2(1.5, 3.5);
    cout << v1.GetX() << ", " << v1.GetY() << endl;
    cout << v2.GetX() << ", " << v2.GetY() << endl;
}
```



#### 13.1.3 템플릿 특수화

템플릿 특수화: 특수한 인수가 들어왔을 때 원래 템플릿의 정의를 따르지 않고, 예외적으로 그 인수에 대한 정의를 따로 할 수 있게 하는 것

```c++
#include <iostream>
#include <string>
using namespace std;


template<typename T>
T getArraySum(const T arr[], int n) {
    T sum = arr[0];
    for (int i = 1; i < n ; i++) {
        sum += arr[i];
    }
    return sum;
};

template<>
string getArraySum(const string arr[], int n) {
    string sum = arr[0];
    for (int i = 1; i < n ; i++) {
        sum += " " + arr[i];
    }
    return sum;
};

int main() {

    int iarr[5] = {3, 1, 4, 1, 5};
    string sarr[3] = {"hello", "world", "minguk"};

    int isum = getArraySum<int>(iarr, 5);
    string ssum = getArraySum(sarr, 3);

    cout << isum << endl;
    cout << ssum << endl;
}
```



#### 13.4.1 비타입 파라미터

