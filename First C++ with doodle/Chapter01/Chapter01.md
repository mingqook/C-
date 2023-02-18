## 1. 출력하기

### 1.1 Hello World!

ex01-01.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
}
```



### 1.2 Hello World! 해석하기

C 언어에서의 함수 : 여러 명령의 묶음

main 함수 : 프로그램의 시작과 끝을 알려주는 특별한 함수, 프로그램이 시작되면 main 함수가 실행되고, main 함수가 종료되면 프로그램도 종료, C 언어로 만든 프로그램이면 반드시 main 함수가 포함되어야 함

C 언어는 하나의 명령의 끝에 반드시 세미콜론(;)을 붙여야 함

stdio : Standard input and output -> 표준 입출력을 담당하는 라이브러리, printf 함수를 포함

stdio.h는 확장자가 .h 인 실제 파일, 해당 파일 안에 printf 를 비롯한 입출력 관련 함수들이 정의되어 있음



### 1.3 printf로 다양한 데이터 출력하기

ex01-02.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    printf("%d + %d = %d\n", 2, 3, 2+3);
}
```

%d : 정수 출력 / %f : 실수 출력 / %c : 1글자 출력 / %s : 문자열 출력



ex01-03.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    printf("%d + %d = %d\n", 2, 3, 2+3);
    printf("%f\n", 3.14);
    printf("%c %c %c\n", 'a', 'b', 'c');
    printf("%s\n", "안녕하세요");
}
```

// : 주석  & /* asbasbasb */ : 주석 블록