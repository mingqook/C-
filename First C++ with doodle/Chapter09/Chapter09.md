## 9. C++ 스타일 기본 문법

### 9.1 C++ 스타일 입출력

iostream : 입출력 스트림에 관련된 것을 모아놓은 라이브러리

cout : 함수가 아닌 객체, <<와 같이 사용 시 오른쪽의 내용을 출력하는 역할, 자료형에 상관없이 알아서 적절한 형태로 춫력

endl : cout에서 줄바꿈을 할 때 쓰는 객체

ex09-01.cpp 파일 생성

```c++
#include <iostream>


int main() {

    std::cout << "Hello, world!" << std::endl;
    
}
```

ex09-02.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

int main() {

    int a = 5;
    double b = 3.14159265358979;
    char c = 'd';

    cout << a << ' ' << b << ' ' << c << endl;
    
}
```



cin : 입력을 받는 객체, << 연산자를 활용

ex09-3.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

int main() {

    int a, b;

    cin >> a >> b;

    cout << a << " + " << b << " = " << a + b << endl;
    
}
```



### 9.2 string

ex09-04.cpp 파일 생성

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    string greeting;

    cout << "이름 입력 : ";
    cin >> name;

    greeting = "안녕하세요, " + name + " 님!";
    
    cout << greeting << endl;
    cout << name << "은 총 " << name.length() << "글자입니다." << endl;
    cout << name << "의 첫 글자는 " << name[0] << "입니다. " << endl;
}
```



### 9.3 C++에서는 의미가 좀 다른 초기화

C++ 에서는 int a(10) 과 같이 초기화 하려는 값을 변수의 중괄호에 넣어 서 가능



### 9.4 레퍼런스와 r-value 참조

#### 9.4.1 레퍼런스 변수

레퍼런스 변수는 생성되는 동시에 특정 변수를 가르켜야 함

레퍼런스 변수는 메모리상에 저장된 공간이 있는 값만 가리킬 수 있음 -> 변수가 아닌 상수나 함수의 리턴 값, 식 등은 가리킬 수 없음

레퍼런스 변수는 일반 변수와 달리 대입 연산자를 사용했을 때 아무 값도 복사되지 않고 우변의 변수를 가리키는 역할만 수행

레퍼런스 변수가 다른 변수를 가리키는 상황을 "참조" 라고 함

참조의 장점 : 원본 변수를 다른 함수에서 직접 수정할 수 있음 / 불필요한 변수의 복사 피할 수 있음



#### 9.4.2 r-value 참조

r-value : 대입 연산자의 좌변에 올 수 없는 값 / 메모리상에 존재하지 않음 / 상수, 식, 주솟값, 함수의 리턴 값 등

l-value : 대입 연산자의 좌변에 올 수 있는 값 / 메모리상 어딘가에 저장 / const가 아닌 이상 새로운 값을 대입할 수 있음 / 변ㅅ, 배열의 각 칸, 구조체 변수 등



### 9.5 범위 기반 for문

ex09-05.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    for (int i:arr) {
        cout << i << ' ';
    }

    cout << endl;
}
```

ex09-06.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    for (int i:arr) {
        i++;
    }

    for (int i:arr) {
        cout << i << ' ';
    }

    cout << endl;
}
```

위 예제를 레퍼런스 변수를 활용하여 수정

ex09-07.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    for (int &i:arr) {
        i++;
    }

    for (int i:arr) {
        cout << i << ' ';
    }

    cout << endl;
}
```



### 9.6 C++ 스타일 함수

#### 9.6.1 함수 오버로딩

C++에서는 매개변수의 종류만 다르다면 같은 이름의 함수를 여러 개 정의할 수 있음 -> 오버로딩

ex09-08.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

int main() {

    int a = 10, b = 20;
    double da = 12.34, db = 56.78;
    char ca = 'A', cb= 'B';

    swap(a,b);
    swap(da, db);
    swap(ca, cb);

    cout << a << " " << b << endl;
    cout << da << " " << db << endl;
    cout << ca << " " << cb << endl;
}
```



#### 9.6.2 디폴트 매개변수

디폴트 매개변수 : 매개변수가 어떤 기본값을 갖게 하는 기능

ex09-10.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

void f(int a=1){
    cout << a << endl;
}

int main() {

    f(123);
    f();
}
```

