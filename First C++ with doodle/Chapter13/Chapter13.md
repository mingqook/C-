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



### 13.2 예외 처리

ex13-04.cpp 파일 생성

```c++
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
```



ex13-05.cpp 파일 생성

```c++
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
```



ex13-06.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


int fact(int n) {

    if (n < 1) {
        throw to_string(n) + " : 자연수가 아닙니다.";
    }
    if (n == 1) {
        return 1;
    }

    return n * fact(n-1);

}

int main() {

    int n, r;
    
    try {
        cout << "자연수를 2개 입력 하세요 : ";
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
```



ex13-07.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


int fact(int n) {

    if (n < 1) {
        throw to_string(n) + " : 자연수가 아닙니다.";
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
            cout << "자연수를 2개 입력 하세요 : ";
            cin >> n >> r;
            cout << comb(n, r) << endl;
        }
        
    }
    catch (const string &e) {
        cout << e << endl;
    }

}
```



ex13-08.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


int fact(int n) {

    if (n < 1) {
        throw to_string(n) + " : 자연수가 아닙니다.";
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
    
    while (true) {
        try {
            
            cout << "자연수를 2개 입력 하세요 : ";
            cin >> n >> r;
            cout << comb(n, r) << endl;
            
        }
        catch (const string &e) {
            cout << e << endl;
        }
    }
    

}
```



catch(...) : catch문을 통해 잡히지 않는 모든 예외들을 처리



### 13.3 auto

auto : 우변의 타입을 분명히 알아낼 수 있을 때 좌변의 타입을 자동으로 정해주는 키워드



### 13.4 함수 포인터, 함수 객체와 람다식

#### 13.4.1 함수 포인터

함수 포인터 : 함수를 가리키는 포인터

함수의 주소를 갖고 오려면 함수 이름 앞에 &를 붙이면 되지만 &를 생략해도 문제 없음

ex13-09.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


int square(int n) {
    return n*n;
}

int myFunc(int n) {
    return n * (n-15) / 2;
}

int arrFnMin(const int arr[], int n, int (*f)(int)) {
    int min = f(arr[0]);
    for (int i = 1; i < n; i++) {
        if (min > f(arr[i])) {
            min = f(arr[i]);
        }
    }
    return min;
}

int main() {

    int arr[7] = {3, 1, -4, 1, 5, 9, -2};

    cout << arrFnMin(arr, 7, square) << endl;
    cout << arrFnMin(arr, 7, myFunc) << endl;

}
```



#### 13.4.2 함수 객체

함수 객체 : 함수처럼 작동하는 객체

특정 클래스에서 () operator를 오버로딩하면 해당 타입의 객체를 만들고 만들어진 객체를 통해 () 연산자를 호출하여 함수처럼 활용 가능

ex13-10.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Equals {
    public:
        Equals(int value) : value(value) {}
        bool operator()(int x) const {
            return x == value;
        }
    private:
        int value;
}

int main() {

    Equals eq(123);

    cout << eq(12) << endl;
    cout << eq(123) << endl;

}
```



함수 포인터는 단순히 한 가지 함수만 가리킬 수 있지만, 함수 객체를 사용하면 여러 변종의 함수를 만들 수 있음

함수 포인터는 가리킬 함수의 리턴 타입과 매개변수 목록을 알아야 하기 때문에 함수 포인터 하나를 가지고 여러 오버로딩된 함수를 가리킬 수 없음

함수 객체를 이용하면 한 가지 이름만을 사용해 여러 오버로딩된 함수를 실행 가능



ex13-11.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


struct Func {
    virtual int operator()(int n) const = 0;
};

struct Square : Func {
    int operator()(int n) const {
        return n * n;
    }
};

struct MyFunc : Func {
    int operator()(int n) const {
        return n * (n - 15) / 2;
    }
};

int arrFnMin(const int arr[], int n, const Func &f) {
    int min = f(arr[0]);
    for (int i = 1; i < n; i++) {
        if (min > f(arr[i])) {
            min = f(arr[i]);
        }
    }
    return min;
}

int main() {

    int arr[7] = {3, 1, -4, 1, 5, 9, -2};

    Square square;
    MyFunc myFunc;

    cout << arrFnMin(arr, 7, square) << endl;
    cout << arrFnMin(arr, 7, myFunc) << endl;

}
```



#### 13.4.3 람다식

람다식 : 익명함수, 특별히 붙여진 이름 없이 본문만 존재하는 함수

람다식 형태 : \[캡처\]\(매개변수_목록\) -> 리턴\_타입 { 함수\_본문}

캡처 : 함수 객체의 멤버 변수 같은존재, 람다식이 정의된 외부 환경을 람다식 안에서 사용하고 싶을 때 사용

람다식의 타입 : 함수 객체 타입

ex13-12.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

int arrFnMin(const int arr[], int n, int(*f)(int)) {
    int min = f(arr[0]);
    for (int i = 1; i < n; i++) {
        if (min > f(arr[i])) {
            min = f(arr[i]);
        }
    }
    return min;
}

int main() {

    int arr[7] = {3, 1, -4, 1, 5, 9, -2};

    cout << arrFnMin(arr, 7, [](int n) -> int {return n*n;}) << endl;
    cout << arrFnMin(arr, 7, [](int n) -> int {return n*(n-15)/2}) << endl;

}
```



### 13.5 friend

friend : 현재 클래스의 모든 멤버를 특정 대상(다른 클래스, 함수 등)에게 모두 공개



### 13.6 메모리 소유권과 스마트 포인터

스마트 포인터 : 메모리 해제를 자동으로 수행, 동적 할당된 객체에 대한 메모리 해제를 자동으로 해주기 위해 등장



#### 13.6.1 메모리 소유권

메모리 소유권 : 어떤 포인터가 객체를 소유하고 있는지는 오로지 코드를 짠 사람만 알고 있음

스마트 포인터 활용 시 소유권에 대한 문제를 일반 포인터보다 체계적으로 관리하고 문법적인 차원에서 다룰 수 있음



#### 13.6.2 unique_ptr

unique_ptr : 한 객체를 가리키는 unique_ptr은 하나만 존재해야 함, 포인터가 복사되는 것을 방지해야 하므로 복사 생성자가 복사 대입 연산자를 사용할 수 없음

release 메서드 활용 시 unique_ptr에서도 소유권 이전 가능

reset 메서드 활용 시 가리키는 객체를 중간에 변경 가능

unique_ptr 소멸자에는 메모리 해제 코드가 포함

ex13-13.cpp 파일 생성

```c++
#include <iostream>
#include <memory>
using namespace std;


class MyClass {
    public:
        MyClass(int x) : x(x) {
            cout << "MyClass(int)" << endl;
        }
        ~MyClass() {
            cout << "~MyClass()" << endl;
        }
        int GetX() const {
            return x;
        }
    private:
        int x;
};


int main() {

    unique_ptr<MyClass> a(new MyClass(5));
    cout << a->GetX() << endl;
    cout << "===== 1 =====" << endl;
    a.reset(new MyClass(7));

    cout << a->GetX() << endl;
    cout << "===== 2 =====" << endl;
    a.reset();

    cout << "===== 3 =====" << endl;
    a.reset(new MyClass(9));

    cout << "===== 4 =====" << endl;

}
```



#### 13.6.3 shared_ptr

shared_ptr : 여러 포인터가 한 객체를 가리킬 수 있음, 한 객체를 여러 포인트가 공유

포인터가 소멸될 때도 객체를 가리키는 포인터가 그 외에 하나라도 남아 있다면 객체를 소멸시키지 않고, 해당 객체를 가리키는 마지막 포인터까지 소멸되고 나서야 해당 객체도 소멸

shared_ptr 역시 delete를 고려해줄 필요 없음

shared_ptr의 핵심은 소유권이 한 포인터에 있지 않다는 것

일반 포인터를 사용 시 많은 포인터 중 정확히 한 포인터가 반드시 메모리 해제를 담당해야 하지만 shared_ptr을 사용하면 객체를 가리키는 포인터가 하나도 남지 않는 순간 자동으로 객체를 삭제

ex13-14.cpp 파일 생성

```c++
#include <iostream>
#include <memory>
using namespace std;


class MyClass {
    public:
        MyClass(int x) : x(x) {
            cout << "MyClass(int)" << endl;
        }
        ~MyClass() {
            cout << "~MyClass()" << endl;
        }
        int GetX() const {
            return x;
        }
    private:
        int x;
};


int main() {

    shared_ptr<MyClass> a(new MyClass(5));
    {
        shared_ptr<MyClass> b = a;
        cout << a->GetX() << endl;
        cout << b->GetX() << endl;
        cout << a.use_count() << endl;
        cout << b.use_count() << endl;
    }

    cout << a->GetX() << endl;
    cout << a.use_count() << endl;

}
```



shared_ptr에서 reset 메서드 사용 시 해당 포인터는 더 이상 객체를 가리키지 않게 되고, use_count도 1 감소

ex13-15.cpp 파일 생성

```c++
#include <iostream>
#include <memory>
using namespace std;


class MyClass {
    public:
        MyClass(int x) : x(x) {
            cout << "MyClass(int)" << endl;
        }
        ~MyClass() {
            cout << "~MyClass()" << endl;
        }
        int GetX() const {
            return x;
        }
    private:
        int x;
};


int main() {

    shared_ptr<MyClass> a(new MyClass(5));
    cout << "===== 1 =====" << endl;
    {
        shared_ptr<MyClass> b = a;
        cout << b.use_count() << endl;
        a.reset();
        cout << b.use_count() << endl;
        cout << "===== 2 =====" << endl;
    }
    cout << "===== 3 =====" << endl;

}
```

shared_ptr은 여러 포인터가 객체를 가르키지만 어느 포인터가 객체를 소유해야 할 지 애매할 경우에 사용



#### 13.6.4 weak_ptr

weak_ptr : shared_ptr이 가리키는 객체를 똑같이 가리킬 수 있지만 소유하지는 않는 포인터 

소유하지 않음 == 소멸에 관여하지 않음

weak_ptr이 객체를 갈켜도 참조하기만 할 뿐 use_count의 값은 변하지 않음

expired 메서드 활용시 weak_ptr이 가리키고 있는 객체가 이미 소멸되었는지 아닌지 확인 가능

lock 메서드 활용 시 객체가 존재할 때는 해당 객체에 대한 shared_ptr을 존재하지 않을 때는 NULL을 가리키는 shared_ptr을 리턴

weak_ptr은 객체를 가리키고 싶지만 소유권은 필요없을 때 활용, 현재 가리키는 대상이 weak_ptr을 통해 역참조하는 것보다 늦게 사라진다는 것이 보장되는 상황



### 13.7 STL

STL : Standard Template Library(표준템플릿라이브러리), 프로그래밍을 편하게 해주는 여러 클래스와 함수가 존재



#### 13.7.1 vector

vector 클래스 템플릿 : 배열과 비슷하지만 배열과는 다르게 칸수가 고정되어 있지 않음, 필요에 따라 칸수가 자동으로 늘어나거나 줄어듬

```c++
#include <vector>
```

push back 메서드 : 새로운 값을 벡터에 삽입, 벡터의 맨 끝에 새로운 원소를 추가

벡터 안의 내용물이 많을 수록 깊은 복사를 할 때 시간이 오래 걸릴 수 있으므로 벡터를 다른 함수로 넘겨줄 때는 레퍼런스로 넘겨주는 것이 가능하다면 레퍼런스로 넘겨주는 것이 좋음



#### 13.7.2 pair

pair : 두 값을 순서쌍처럼 묶어놓을 수 있는 컨테이너, 두 값의 타입이 달라도 문제 없음

```c++
#include <utility>
```



#### 13.7.3 map

 map : python의 dict 역할, key-value 쌍, key 끼리 크기 비교가 가능해야 함, 

```c++
#include <map>
```



#### 13.7.4 sort

sort : 배열 따위의 원소들을 크기 순으로 정렬

```c++
#include <algorithm>
```
