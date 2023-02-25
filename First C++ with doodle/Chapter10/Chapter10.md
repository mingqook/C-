## 10. 객체와 클래스

### 10.1 네임스페이스

#### 10.1.1 네임스페이스의 개념

C/C++ 에서는 같은 스코프에 같은 이름의 전역 변수나 함수를 만들 수 없음

변수나 함수를 어떤 네임스페이스 안에 잘 나누어서 선언하면 구분이 가능해짐



#### 10.1.2 네임스페이스 만들고 사용하기

:: 앞에 아무것도 붙어 있지 않으면 전역 네임스페이스에서 정의한 것과 같음

ex10-01.cpp 파일 생성

```c++
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
```



ex10-02.cpp 파일 생성

```c++
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
        minguk::n = 30;
    }
}

int main() {

    minguk::set();
    cout << minguk::n << endl;

    qook::set();
    cout << minguk::n << endl;

}
```



#### 10.1.3 네임스페이스와 함수 정의

소스가 여러 파일로 이루어져 있는 경우에는 함수의 선언과 정의가 다른 파일에 분리되어 있는 경우가 많은데, 이 때는 같은 이름의 네임스페이스를 파일 별로 만들면 됨

함수를 한 번 선언한 이후에는 정의를 굳이 네임스페이스 안에 넣을 필요는 없지만 ::를 통해서 어느 네임스페이스의 함수인지 밝혀야 함



#### 10.1.4 중첩 네임스페이스

중첩 네임스페이스 : 네임스페이스 안의 네임스페이스

 ex10-03.cpp 파일 생성

```c++
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
```



#### 10.1.5 using문

using을 사용하면 다른 네임스페이스 안에 선언된 모든 이름을 네임스페이스를 명시하지 않고도 자기 네임스페이스에 선언된 것처럼 사용 가능

ex10-04.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

namespace minguk {
    int n;
    void set() {
        n = 20;
    }
}


int main() {

    using namespace minguk;

    set();
    cout << n << endl;

}
```



### 10.2 클래스와 객체

#### 10.2.1 클래스와 객체의 개념

객체 : 자료 저장 + 기능 -> 자료를 저장하고 그 자료들을 가지고 특정한 기능을 수행하는 무언가

클래스 : 객체들을 찍어내는 틀

클래스는 실체가 없고, 객체가 어떤 식으로 만들어져야 하는가에 대한 정보만 가지고 있음



#### 10.2.2 TV 클래스 만들기

#### 10.2.3 접근 제어

접근 제어 : 특정 멤버에 접근하는 것을 특정 범위까지로 제한 하는 것

접근 제어를 하게되면 어디선가는 멤버를 사용할 수 있고, 어디선가는 멤버를 사용하지 못하게 됨

접근 제어는 접근 제어 지시자를 통해 가능

접근 제어 지시자 종류 : public(누구든지 어디서나 접근 가능, 어디서나 수정 가능, 메서드 접근 가능), protected, private(클래스 내부에서만 접근 가능)

구조체에서는 접근 제어를 특별히 지정하지 않으면 기본적으로 public 속성이 적용

ex10-05.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

struct TV {
    private:
        bool powerOn;
        int channel;
        int volume;
    public:
        void on() {
            powerOn = true;
        }
        void off() {
            powerOn = false;
        }
        void setChannel(int chn) {
            if (chn >= 1 && chn <= 999) {
                channel = chn;
            }
        }
        int getChannel() {
            return channel;
        }
        void setVolume(int vol) {
            if (vol >= 0 && vol <= 100) {
                volume = vol;
            }
        }
        int getVolume() {
            return volume;
        }
};


int main() {

    TV mytv;

    mytv.on();
    mytv.setChannel(10);
    mytv.setVolume(50);

    cout << "현재 채널은 " << mytv.getChannel() << endl;
    cout << "현재 볼률음 " << mytv.getVolume() << endl;
}
```



구조체의 기본 접근제어자는 public, 클래스의 기본 접근제어자는 private



### 10.3 this 포인터

this 포인터 : 클래스 내부에서 자기 자신을 가리킬 때 사용하는 특별히 약속된 포인터

ex10-06.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class MyClass {
    public:
        void PrintThis() {
            cout << "나의 주소는 " << this << endl;
        }
};

int main() {
    
    MyClass a, b;

    cout << "객체 a의 주소는 " << &a << endl;
    cout << "객체 b의 주소는 " << &b << endl;
    
    a.PrintThis();
    b.PrintThis();
}
```



### 10.4 객체의 생성과 소멸

생성자 : 객체가 생성될 때 자동으로 실행, 객체를 초기화, 리턴 타입을 적지 않고 클래스의 이름과 동일

소멸자 : 객체가 소멸될 때 자동으로 실행, 객체가 할당했던 메모리를 해제, 리턴 타입을 적지 않고 클래스 이름 앞에 ~를 붙임



#### 10.4.1 객체의 생성과 소멸 시기

ex10-07.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class MyClass {
    public:
        MyClass() {
            cout << "생성자가 호출 되었다!!" << endl;
        }
        ~MyClass() {
            cout << "소멸자가 호출되었다!!" << endl;
        }
};

// MyClass globalObj;

void testLocalObj() {
    cout << "=== testLocalObj 함수 시작 ===" << endl;
    MyClass localObj;
    cout << "=== testLocalObj 함수 끝 ===" << endl;
}

int main() {
    cout << "=== main 함수 시작 ===" << endl;
    testLocalObj();
    cout << "=== main 함수 끝 ===" << endl;
}
```

ex10-08.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class MyClass {
    public:
        MyClass() {
            cout << "생성자가 호출 되었다!!" << endl;
        }
        ~MyClass() {
            cout << "소멸자가 호출되었다!!" << endl;
        }
};

MyClass globalObj;

void testLocalObj() {
    cout << "=== testLocalObj 함수 시작 ===" << endl;
    // MyClass localObj;
    cout << "=== testLocalObj 함수 끝 ===" << endl;
}

int main() {
    cout << "=== main 함수 시작 ===" << endl;
    testLocalObj();
    cout << "=== main 함수 끝 ===" << endl;
}
```



지역 변수, 지역 객체 : 선언 시 생성되고 객체가 선언된 함수 종료 시 소멸

전역변수, 전역 객체 : main 함수 시작 전 생성되고, main 함수 종료 후 소멸



#### 10.4.2 생성자 활용하기

#### 10.4.3 생성자 오버로딩과 기본 생성자

ex10-09.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class Complex {
    public:
        Complex() {
            real = 0;
            imag = 0;
        }
        Complex(double real_, double imag_) {
            real = real_;
            imag = imag_;
        }

        double GetReal() {
            return real;
        }

        void SetReal(double real_) {
            real = real_;
        }

        double GetImag() {
            return imag;
        }

        void SetImag(double imag_) {
            imag = imag_;
        }

    private:
        double real;
        double imag;
}

int main() {
    Complex c1;
    Complex c2 = Comlex(2,3);
    Complex c3(2,3);

    cout << "c1 = " << c1.GetReal() << ", " <<  c1.GetImag() << endl;
    cout << "c2 = " << c2.GetReal() << ", " <<  c2.GetImag() << endl;
    cout << "c3 = " << c3.GetReal() << ", " <<  c3.GetImag() << endl;
}
```



클래스에 따로 생성자를 만들지 않았을 때는 기본 생성자가 자동으로 만들어지지만 클래스 안에 생성자가 어떤 것이든 하나라도 있으면 기본 생성자느 사라지고 직접 만든 생성자만 사용 가능



### 10.5 생성자의 다양한 사용법

ex10-10.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class Complex {
    public:
        Complex(double real_=0, double imag_=0) {
            real = real_;
            imag = imag_;
        }

        double GetReal() {
            return real;
        }

        void SetReal(double real_) {
            real = real_;
        }

        double GetImag() {
            return imag;
        }

        void SetImag(double imag_) {
            imag = imag_;
        }

    private:
        double real;
        double imag;
}

int main() {
    Complex c1;
    Complex c2 = Comlex(2,3);
    Complex c3(2,3);

    cout << "c1 = " << c1.GetReal() << ", " <<  c1.GetImag() << endl;
    cout << "c2 = " << c2.GetReal() << ", " <<  c2.GetImag() << endl;
    cout << "c3 = " << c3.GetReal() << ", " <<  c3.GetImag() << endl;
}
```



### 10.6 정적 멤버

멤버 변수는 객체를 만들 때마다 새로 생성

멤버 메서드는 객체를 만들지 않으면 사용할 수 없음



#### 10.6.1 정적 멤버 메서드

정적(static) 멤버는 객체에 소속되어 있지 않음

정적 멤버 메서드는 메서드를 호출할 때 this 포인터가 넘어가지 않음 -> 정적 메서드는 개체 없이도 실행 가능 -> static을 가장 앞에 붙여서 선언

정적 메서드는 클래스 이름을 네임스페이스로 하는 전역 함수처럼 생각할 수 있음 -> 클래스 내부에 선언되어 있기 때문에 전역 함수와 달리 매개변수로 받은 클래스의 private 매개변수에 직접 접근 가능

ex10-11.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class Color {
    public:
        Color() : r(0), g(0), b(0) {}
        Color(float r, float g, float b) : r(r), g(g), b(b) {}

        float GetR() {
            return r;
        }
        float GetG() {
            return g;
        }
        float GetB() {
            return b;
        }

        static Color MixColors(Color a, Color b) {
            return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2)
        }

    private:
        float r;
        float g;
        float b;
}

int main() {
    Color red = Color(1,0,0);
    Color blue = Color(0,0,1);
    Color purple = Color::MixColors(red, blue);

    cout << red.GetR() << ", " << red.GetG() << ", " << red.GetB() << endl;
    cout << blue.GetR() << ", " << blue.GetG() << ", " << blue.GetB() << endl;
    cout << purple.GetR() << ", " << purple.GetG() << ", " << purple.GetB() << endl;
}
```



#### 10.6.2 정적 멤버 변수

정적 멤버 변수 : 객체에 포함되어 있지 않기 대문에 객체를 새로 만든다고 해서 새로 생기지도 않고 객체를 만들지 않아도 존재

정적 멤버 변수의 초기화는 클래스 이름을 네임스페이스로 갖는 전역 변수를 초기화 한다고 생각

ex10-12.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class Color {
    public:
        Color() : r(0), g(0), b(0), id(idCounter++) {}
        Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {}

        float GetR() {
            return r;
        }
        float GetG() {
            return g;
        }
        float GetB() {
            return b;
        }
        int GetId() {
            return id;
        }

        static Color MixColors(Color a, Color b) {
            return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2)
        }

    private:
        static int idCounter;
        int id;
        float r;
        float g;
        float b;
}

int Color::idCounter=1;

int main() {
    Color red = Color(1,0,0);
    Color blue = Color(0,0,1);
    Color purple = Color::MixColors(red, blue);

    cout << red.GetId() << endl;
    cout << blue.GetId() << endl;
    cout << purple.GetId() << endl;
}
```





### 10.7 상수형 메서드

const를 활용하여 멤버 메서드를 상수형으로 지정 가능

메서드가 상수형이라는 것은 메서드 내부에서 자기 객체의 멤버를 바꿀 수 없다는 것을 의미

상수형 메서드 안에서 객체의 멤버 변수를 다른 값으로 바꾸려면 컴파일 에러 발생

상수형 메서드는 메서드의 소괄호 뒤에  const를 붙임 -> int GetMoney() const { ---}

객체를 상수형으로 선언한 경우에는 상수형 메서드만 호출 가능



## 10.8 메서드 선언과 정의 분리하기

선언만 클래스 안에서하고 정의는 클래스 밖에서 수행

ex10-13.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

class Vector2 {
    public:
        Vector2();
        Vector2(float x, float y);
        float GetX() const;
        float GetY() const;
    private:
        float x, y;
}

int main() {
    Vector2 a(2,3);
    cout << "a = ( " << a.GetX() << ", " << a.GetY() << " )" << endl;
}

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x;}
float Vector2::GetY() const { return y;}
```



### 10.9 연산자 오버로딩

연산자 오버로딩 : 원래 연산이 되지 않는 타입끼리의 연사자를 새로 정의 하는 것



#### 10.9.1 멤버 메서드로 객체끼리 연산하기

ex10-14.cpp 파일 생성

```c++
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
```



#### 10.9.2 사칙연산 오버로딩

ex10-15.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

/************** 클래스 정의 *******************/
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


/************** main 함수 *******************/

int main() {
    Vector2 a(2,3), b(5,6);
    Vector2 c1 = a+b;
    Vector2 c2 = a-b;

    cout << "c1 = ( " << c1.GetX() << ", " << c1.GetY() << " )" << endl;
    cout << "c2 = ( " << c2.GetX() << ", " << c2.GetY() << " )" << endl;
    cout << "c3 = ( " << c3.GetX() << ", " << c3.GetY() << " )" << endl;
}

/************** 함수 정의 *******************/
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

```



ex10-16.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

/************** 클래스 정의 *******************/
class Vector2 {
    public:
        Vector2();
        Vector2(float x, float y);
        float GetX() const;
        float GetY() const;
        Vector2 operator+(const Vector2 other) const;
        Vector2 operator-(const Vector2 other) const;
        Vector2 operator*(const float k) const;
        float operator-(const Vector2 other) const;
    private:
        float x, y;
}
Vector2 operator*(const float k, const Vector2 v);

/************** main 함수 *******************/

int main() {
    Vector2 a(2,3), b(5,6);
    Vector2 c1 = a * 3.1;
    Vector2 c2 = 3.1 * a;
    float c3 =  a * b;

    cout << "c1 = ( " << c1.GetX() << ", " << c1.GetY() << " )" << endl;
    cout << "c2 = ( " << c2.GetX() << ", " << c2.GetY() << " )" << endl;
    cout << "c3 = ( " << c3 << endl;
}

/************** 함수 정의 *******************/
Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x;}
float Vector2::GetY() const { return y;}
Vector2 Vector2::operator+(const Vector2 other) const {
    return Vector2(x + other.x, y+other.y);
}
Vector2 Vector2::operator-(const Vector2 other) const {
    return Vector2(x - other.x, y-other.y);
}
Vector2 Vector2::operator*(const float k) const {
    return Vector2(x*k, y*k);
}
Vector2 operator*(const float k, const Vector2 v) const {
    return Vector2(k * v.GetX(), k * v.GetY());
}
float Vector2::operator*(const Vector2 other) const {
    return x * other.x + y * other.y;
}
```

