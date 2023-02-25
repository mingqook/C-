## 11. 동적 할당과 객체 복사

### 11.1 동적 할당

정적 할당 : 선언된 변수들이 메모리를 얼마나 사용할지를 컴파일 시간에 예측할 수 있고, 사용하기 편리, 메모리가 언제 할당되고 해제되는지가 정확히 정해져 있기 때문에 이를 통제할 방법이 없음

동적 할당 : 프로그램 실행 도중에 새로운 메모리 공간을 사용할 수 있게 할당하는 것, 정확히 언제 메모리를 얼만큼 할당하고, 할당된 메모리를 언제 해제할 것인지 코들르 짜는 사람이 직접 지정 가능, 필요할 때 필요한 만큼의 메모리를 할당해서 쓰고 해제할 수 있게 됨



#### 11.1.1 변수 동적 할당하기

new : 동적 할당 활용시 사용하느 키워드

메모리 누수 : 메모리를 다 썼는데도 해제하지 않아 나중에 새로운 메모리 공간이 필요할 때 해당 공간을 다시 쓰지 못하는 낭비 현상

모든 동적 할당된 메모리는 반드시 해제되어야 하고, 반드시 한 번만 해제되어야 함

ex11-01.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


int main() {
    
    int *a = new int(5);

    cout << a << endl;
    cout << *a << endl;
    *a =10;
    cout << a << endl;
    cout << *a << endl;

    delete a;
}
```



#### 11.1.2 배열 동적 할당하기

동적 할당된 배열의 칸수에는 변수를 넣을 수 있음 -> 처음 배열을 만들어줄 때 칸수를 변수로 설정할 수 있다는 것이지, 배열을 만든 이후로 배열의 칸수가 시시때떄로 변할 수 있는 것은 아님

배열 메모리를 해제할 때는 delete 뒤에 []를 붙여야 함



#### 11.1.3 객체 동적 할당하기

ex11-02.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Vector2 {
    public:
        Vector2() : x(0), y(0) {
            cout << this << " : Vector2()" << endl;
        }
        Vector2(float x, float y) : x(x), y(y) {
            cout << this << " : Vector2(float, float)" << endl;
        }
        ~Vector2() {
            cout << this << " : ~Vector2()" << endl;
        }

        float GetX() const { return x;}
        float GetY() const { return y;}

    private:
        float x, y;
}

int main() {
    
    cout << "main 시작" << endl;

    Vector2 s1;
    Vector2 s2(2,3);

    Vector2 *d1 = new Vector2;
    Vector2 *d2 = new Vector2(4,5);

    cout << "d1 = ( " << d1 -> GetX() << ", " << d1 -> GetY() << " )" << endl;
    cout << "d2 = ( " << d2 -> GetX() << ", " << d2 -> GetY() << " )" << endl;

    delete d1;
    delete d2;

    cout << "main  끝 " << endl;
}


```



### 11.2 깊은 복사와 얕은 복사

얕은 복사 : 주솟값만 복사, 참조만 복사

깊은 복사 : 기존 아는 복사처럼 값만 복사



### 11.3 복사 생성자와 복사 대입 연산자

#### 11.3.1 String 클래스 만들기

객체 내에서 동적 할당된 메모리는 별다른 이유가 없으면 반드시 해제도 객체 내에서 해야 함

NULL 포인터는 delete를 해줘도 문제 없음

ex11-03.cpp 파일 생성

```c++
#include <iostream>
#include <string.h>
using namespace std;


class String {
    public:
        String() {
            strData = NULL;
            len = 0;
        }
        String(const char *str) {
            len = strlen(str);
            strData = new char[len+1];
            strcpy(strData, str);
        }
        ~String() {
            if (strData) {
                delete [] strData;
            }
        }
        const char *GetStrData() const {
            if (strData) return strData;
            return "";
        }
        int GetLen() const {
            return len;
        }
    private:
        char *strData;
        int len;
};

int main() {
    
    String s1;
    String s2("Hello");

    cout << s1.GetLen() << endl;
    cout << s1.GetStrData() << endl;
    cout << s2.GetLen() << endl;
    cout << s2.GetStrData() << endl;

}


```



#### 11.3.2 복사 생성자 오버로딩

복사 생성자 : 객체가 복사생성(객체를 선언하는 동시에 어떤 다른 객체의 값으로 초기화 하는 경우)될 때 실행되는 생성자

ex11-04.cpp 파일 생성

```c++
#include <iostream>
#include <string.h>
using namespace std;


class String {
    public:
        String() {
            strData = NULL;
            len = 0;
        }
        String(const char *str) {
            len = strlen(str);
            strData = new char[len+1];
            strcpy(strData, str);
        }
        String(const String &rhs) {
            len = rhs.len;
            strData = new char[len+1];
            strcpy(strData, rhs.strData);
        }
        ~String() {
            if (strData) {
                delete [] strData;
            }
        }
        const char *GetStrData() const {
            if (strData) return strData;
            return "";
        }
        int GetLen() const {
            return len;
        }
    private:
        char *strData;
        int len;
};

int main() {
    
    String s1("Hello");
    String s2=s1;

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;

}


```



#### 11.1.3 복사 대입 연산자 오버로딩

복사 대입 연산자 (operator =)

ex11-05.cpp 파일 생성

```c++
#include <iostream>
#include <string.h>
using namespace std;


class String {
    public:
        String() {
            strData = NULL;
            len = 0;
        }
        String(const char *str) {
            len = strlen(str);
            strData = new char[len+1];
            strcpy(strData, str);
        }
        String(const String &rhs) {
            len = rhs.len;
            strData = new char[len+1];
            strcpy(strData, rhs.strData);
        }
        ~String() {
            if (strData) {
                delete [] strData;
            }
        }
        String &operator=(const String &rhs) {
            if (this != &rhs){
                len = rhs.len;
                delete[] strData;
                strData = new char[len+1];
                strcpy(strData, rhs.strData);
            }
            return *this;
        }
        const char *GetStrData() const {
            if (strData) return strData;
            return "";
        }
        int GetLen() const {
            return len;
        }
    private:
        char *strData;
        int len;
};

int main() {
    
    String s1("Hello");
    String s2("World");
    s2 = s1;

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;

}
```



### 11.4 이동 시맨틱

객체 내에서 동적 할당된 메모리는 특별한 이유가 없다면 얕은 복사가 일어나면 안되고, 복사 생성자와 복사 대입 연산자를 오버로딩 해 해당 상황이 일어나지 않도록 방지해야 함

이동 시맨틱 : 이동이 일어나면 객체가 가리키는 데이터가 복사되지 않고 단순히 이동, 복사 이후 바로 사라지는 객체에 대해서는 의도적으로 얕은 복사를 수행 해 데이터를 복사하지 않고 이동만 시키도록 하는 문법



### 11.5 이동 생성자와 이동 대입 연산자

#### 11.5.1 String 클래스 보강하기

ex11-06.cpp 파일 생성

```c++
#include <iostream>
#include <string.h>
using namespace std;


class String {
    public:
        String() {
            cout << "String() : " << this << endl;
            strData = NULL;
            len = 0;
        }
        String(const char *str) {
            cout << "String(const char*) : " << this << endl;
            len = strlen(str);
            alloc(len);
            strcpy(strData, str);
        }
        String(const String &rhs) {
            cout << "String(const String&) : " << this << endl;
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);
        }
        ~String() {
            cout << "String(const String&) : " << this << endl;
            release();
            strData = NULL;
        }
        String &operator=(const String &rhs) {
            cout << "String &operator=(const String&) : " << this << endl;
            if (this != &rhs){
                release();
                len = rhs.len;
                alloc(len);
                strcpy(strData, rhs.strData);
            }
            return *this;
        }
        const char *GetStrData() const {
            return strData;
        }
        int GetLen() const {
            return len;
        }
    private:
        void alloc(int len) {
            strData = new char[len + 1];
            cout << "strData 할당됨 : " << (void*)strData << endl;
        }
        void release() {
            if (strData) cout << "strData 해제됨 : " << (void*)strData << endl;
        }
        char *strData;
        int len;

};

String GetName() {
    cout << "=====2=========" << endl;
    String res("Minguk");
    cout << "=====3=========" << endl;
    return res;
}

int main() {
    
    String a;
    cout << "=====1=========" << endl;
    a=GetName();
    cout << "=====4=========" << endl;

}
```



#### 11.5.2 이동 생성자 및 이동 대입 연산자 오버로딩

ex11-07.cpp 파일 생성

```c++
#include <iostream>
#include <string.h>
using namespace std;


class String {
    public:
        String() {
            cout << "String() : " << this << endl;
            strData = NULL;
            len = 0;
        }
        String(const char *str) {
            cout << "String(const char*) : " << this << endl;
            len = strlen(str);
            alloc(len);
            strcpy(strData, str);
        }
        String(const String &rhs) {
            cout << "String(const String&) : " << this << endl;
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);
        }
        String(String &&rhs) {
            cout << "String(String&&) : " << this << endl;
            len = rhs.len;
            strData = rhs.strData;
            rhs.strData = NULL;
        }
        ~String() {
            cout << "String(const String&) : " << this << endl;
            release();
            strData = NULL;
        }
        String &operator=(const String &rhs) {
            cout << "String &operator=(const String&) : " << this << endl;
            if (this != &rhs){
                release();
                len = rhs.len;
                alloc(len);
                strcpy(strData, rhs.strData);
            }
            return *this;
        }
        String &operator=(String &&rhs) {
            cout << "String &operator=(String&&) : " << this << endl;
            len = rhs.len;
            strData = rhs.strData;
            rhs.strData = NULL;
            return *this;
        }
        const char *GetStrData() const {
            return strData;
        }
        int GetLen() const {
            return len;
        }
    private:
        void alloc(int len) {
            strData = new char[len + 1];
            cout << "strData 할당됨 : " << (void*)strData << endl;
        }
        void release() {
            if (strData) cout << "strData 해제됨 : " << (void*)strData << endl;
        }
        char *strData;
        int len;

};

String GetName() {
    cout << "=====2=========" << endl;
    String res("Minguk");
    cout << "=====3=========" << endl;
    return res;
}

int main() {
    
    String a;
    cout << "=====1=========" << endl;
    a=GetName();
    cout << "=====4=========" << endl;

}
```

