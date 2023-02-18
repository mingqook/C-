## 2. 변수와 연산자

### 2.1 변수 사용하기

메모리 : RAM, 운영체제나 프로그램이 실행되는 동안 여러 가지 정보를 저장, C 언어에서는 변수를 통해 메모리에 접근해서 정보를 저장하거나 가져옴

변수 : 어떤 값을 담는 공간(메모리의 어딘가에 할당 됨), 컴퓨터는 0과 1로 이루어져 있기 때문에 변수에 담겨 있는 값도 결국 0과 1로 표현

#### 2.1.1 변수의 선언과 대입

ex02-01.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a;
    a = 3;
    printf("%d\n", a);
}
```

ex02-02.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a;
    a = 3;
    printf("%d\n", a);
    a = 5;
    printf("%d\n", a);
}
```



#### 2.1.2 변수의 초기화

초기화 : 변수를 선언함과 동시에 특정 값을 대입

ex02-03.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 2;
    int b = 3;
    printf("%d + %d = %d\n", a, b, a+b);
}
```

ex02-04.cpp 파일 생성

``` C++
#include <stdio.h>

int main() {
    int a = 2;
    int b = 3;
    int sum = a+b;
    printf("%d + %d = %d\n", a, b, sum);
}
```



#### 2.1.3 변수의 이름

변수의 이름은 원칙적으로 영어 대소문자, 숫자, 언더스코어(_) 조합으로만 가능

변수 이름의 첫 글자는 숫자일 수 없음



### 2.2 자료형

자료형 : 타입, 자료의 형태 혹은 종류

자료형은 변수를 0과 1로 표현하였을 때 이를 어떻게 해석할 것인지 알려주는 역할을 수행

변수는 자료형에 따라 크기가 다를 수 있고, 해석되는 방식도 다름

#### 2.2.1 int와 float

int : 정수

ex02-5.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    int add = a + b;
    int sub = a - b;
    int mul = a * b;
    int div = a / b;
    int mod = a % b;

    printf("%d + %d = %d\n", a, b, add);
    printf("%d - %d = %d\n", a, b, sub);
    printf("%d * %d = %d\n", a, b, mul);
    printf("%d / %d = %d\n", a, b, div);
    printf("%d %% %d = %d\n", a, b, mod);
}
```

float : 실수

ex02-06.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    float a = 9.8;
    float b = 3.14;
    float add = a + b;
    float sub = a - b;
    float mul = a * b;
    float div = a / b;

    printf("%f + %f = %f\n", a, b, add);
    printf("%f - %f = %f\n", a, b, sub);
    printf("%f * %f = %f\n", a, b, mul);
    printf("%f / %f = %f\n", a, b, div);
}
```

 부동 소수점 오차 : 컴퓨터가 소수를 처리하는 방식상 불가피하게 발생하는 실제 계산값과의 오차

오차를 줄이기 위해 정밀도가 두 배인 double 자료형을 사용하기도 함



#### 2.2.2 비트와 바이트

비트(bit) : 0과 1을 담을 수 있는 자리 

바이트(byte) : 8비트 묶음

int 자료형은 4바이트 자료형 = 32비트 자료형 -> int 변수 하나에는 2^32가지의 정수 표현 가능



#### 2.2.3 이진법과 정수 자료형

일반적인 이진법으로는 음수 표현이 불가능 -> 맨 앞 비트를 부호 비트로 사용

부호 비트가 0일 때는 양수, 1일 때는 음수로 생각 -> 부호 비트가 1일 때는 해당 이진법의 값에서 이진법의 최대값을 빼줌 (ex. 1001 = 9 - 16 = -7)

맨 앞의 비트를 부호 비트로 활용하는 지 여부에 따라 "부호 있는 정수"와 "부호 없는 정수"로 분류

#### 2.2.4 여러 가지 자료형

(부호 있는) 정수형

​	char : 1바이트 = 8비트

​	short : 2바이트 = 16비트

​	long : 4바이트 = 32비트

​	int : 4바이트 = 32비트

​	long long : 8바이트 = 64비트

부호 없는 정수형

​	unsigned char : 1바이트 = 8비트

​	unsigned short : 2바이트 = 16비트

​	unsigned long : 4바이트 = 32비트

​	unsigned int : 4바이트 = 32비트

​	unsigned long long : 8바이트 = 64비트

실수형

​	float : 4바이트 = 32비트

​	double : 8바이트 = 64비트



#### 2.2.5 sizeof 연산자

sizeof : 자료형 또는 변수의 크기 확인

ex02-07.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    printf("%d %d %d %d\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double));
    int a; char b; float c; double d;
    printf("%d %d %d %d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));
}
```



### 2.3 형변환

형변환(type conversion) : 서로 다른 자료형 사이를 변환하는 것

ex02-08cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 3.14;
    float b = 10;
    printf("a=%d. b=%f\n", a, b);
}
```

자료형이 같은 변수끼리는 쉼표로 구분하여 한 번에 선언 가능

ex02-09.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int math=90, korean = 95, english = 96;
    int sum = math + korean + english;
    double avg = sum /3;

    printf("평균 점수 : %f\n", avg);
}
```

제대로 된 평균 값을 구하기 위해  int형인 sum의 값을 avg를 구할 때는 수동으로 double 자료형으로 변환

형변환하고 싶은 값 앞에 괄호를 쓰고 바꾸고 싶은 자료형을 넣으면 됨

ex02-10.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int math=90, korean = 95, english = 96;
    int sum = math + korean + english;
    double avg = (double)sum /3;

    printf("평균 점수 : %f\n", avg);
}
```



### 2.4 char형과 ASCII 코드

### 2.4.1 문자끼리의 덧셈

ex02-11.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    printf("%c + %c = %c\n", '2', '3', '2' + '3');
}
```

C 언어에서 '문자'는 작은 따옴표 안에 들어가야 하고, 작은따옴표 안에 들어갈 수 있는 문자로는 알파벳 대소문자, 숫자, 그리고 몇몇 기호만 가능

a와 'a'가 다른 의미이듯 2와 '2'도 다른 의미

ex02-12.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    printf("%c %d\n", '2', '2');
}
```

C 언어에서 '2'는 50과 같음 -> ASCII 값

'2'의 ASCII 값 = 50, '3'의 ASCII 값 = 51 -> '2' + '3' = 50 + 51 = 101 -> 101의 ASCII 값을 갖는 문자는 'e' 

따라서 '2' + '3' = 'e' 라는 결과가 도출

ex02-13.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    printf("%c %d\n", '2', '2');
    printf("%c %d\n", 50, 50);
}
```

'2'와 50은 컴퓨터 내부적으로는 같은 의미지만 어떤 자료형을 사용하여 출력하느냐에 따라서 다르게 출력됨



#### 2.4.2 문자형으로서의 char형

컴퓨터에서 문자를 저장할 때도 마찬가지로 문자 자체가 아닌 문자에 해당하는 ASCII 값을 저장

문자를 저장할 때도 정수형 변수를 사용 

일반적으로 쓰는 ASCII 코드는 127번까지만 있기 때문에 문자는 -128부터 127까지의 정수를 담을 수 있는 1바이트짜리 char형에 저장

ex02-14.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    char a ='A';
    printf("%c의 ASCII 값은 %d\n", a, a);
}
```



### 2.5 변수로 연산하기

#### 2.5.1 대입 연사자와 복합 대입 연산자

ex02-15.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 5;
    printf("원래 a의 값은 %d였다.\n", a);
    a = a+3;
    printf("a에 3을 더했더니 %d이 되었다!!.\n", a);
}
```



#### 2.5.2 증감 연산자

정수형 변수를 1 증가 또는 감소시킬 떄는 ++, --를 활용\

ex02-16.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 5;
    printf("a는 원래 %d였다.\n", a);
    a++;
    printf("1 증가해서 %d이 됐다.\n", a);
    a--;
    printf("1 감소해서 %d이 됐다.\n", a);
}
```

ex02-17.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 5;
    int b;

    b = ++a;
    printf("=== 전치 증가 연산 === \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    b = a++;
    printf("=== 후치 증가 연산 === \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}
```

전치 증가 연산 (++a) 는 변수 앞에 연산자를 활용 -> a가 1 증가한 후 증가된 값을 대입

후치 증가 연산 (a++) 는 변수 뒤에 연산자를 활용 -> a의 값이 대입된 후 a가 1이 증가



#### 2.5.3 비교 연산자와 진릿값

bool : 1바이트 자료형(컴퓨터의 최소가 1바이트 이기 떄문에 어쩔수 없이 7비트 손해)

ex02-18.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 30;
    int b = 50;

    bool p = a > b;
    bool q = a < b;
    bool r = a == b;

    printf("%d는 %d보다 크다 : %d\n", a, b, p);
    printf("%d는 %d보다 작다 : %d\n", a, b, q);
    printf("%d는 %d과 같다 : %d\n", a, b, r);
}
```



#### 2.5.4 논리 연산자

논리 연산자 : bool을 연결하거나 부정하는 연산자

&&(그리고), ||(또는), !(아니다, 부정)

ex02-19cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a = 3;

    bool p = a >=1 && a <=10;
    bool q = a==3 || a==7;
    bool r = !q;

    printf("%d\n", p);
    printf("%d\n", q);
    printf("%d\n", r);
}
```



#### 2.5.5 연산자의 우선순위

![TableOfOperators](https://t1.daumcdn.net/cfile/tistory/998286475B32392D3E)