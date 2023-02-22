## 8. C언어 고급 기능

### 8.1 상수 만들기

#### 8.1.1 const 키워드

변수를 초기화 할 때 앞에 const 키워드를 붙이면 변수가 생성된 이후로 변수가 소멸될 때까지 변수에 새로운 값을 대입할 수 없음

상수는 모든 글자를 대문자로 쓰는 것이 일반적

const 속성이 있는 변수는 반드시 생성과 동시에 값을 넣어야 함 = 초기화를 반드시 해줘야 함

ex08-01.cpp 파일 생성

```c++
#include <stdio.h>

const double PI = 3.14159265358979;

double getArea(double r) {
    return PI * r * r;
}

int main() {

    printf("%f", getArea(10));

}
```

const 선언된 변수 초기화 시 숫자 상수만 넣어줘야만 하는 것은 아님. 



#### 8.1.2 매크로

매크로 : 컴파일 전에 특정 단어를 다른 표현으로 바꾸는 역할

ex08-02.cpp 파일 생성

```c++
#include <stdio.h>
#define PI 3.14159265358979

double getArea(double r) {
    return PI * r * r;
}

int main() {

    printf("%f", getArea(10));

}
```



#### 8.1.3 enum

enum 활용 시 열거형을 편하게 만들 수 있음

ex08-03.cpp 파일 생성

```c++
#include <stdio.h>

enum {
    MAINMENU_STATE,
    PLAYING_STATE,
    PAUSED_STATE,
    GAMEOVER_STATE
};

int main() {

    printf("%d\n", MAINMENU_STATE);
    printf("%d\n", PLAYING_STATE);
    printf("%d\n", PAUSED_STATE);
    printf("%d\n", GAMEOVER_STATE);

}
```



### 8.2 매크로 자세히 알아보기

매크로의 원리는 지정된 이름을 다른 표현으로 교체하는 것이기 때문에 값이 아니더라도 웬만한 표현은 모두 정의 가능

이름은 한 단어야 하지만 다른표현은 여러 단어도 가능

ex08-04.cpp 파일 생성

```c+
#include <stdio.h>

#define MAIN int main
#define ULL unsigned long long
#define NUM 1234
#define PLUS +
#define PNT printf

MAIN() {

    ULL m = NUM PLUS 1;

    PNT("%d", NUM);

}
```



매크로를 통해 함수 형식을 정의할 때는 계산 순서 영향 문제를 피하기 위해 ()를 적절히 활용해야 함

ex08-05.cpp 파일 생성

```c++
#include <stdio.h>

#define SQUARE(X) X * X

int main() {

    int a = 5;
    printf("%d", SQUARE(a));

}
```

ex08-06.cpp 파일 생성

```c++
#include <stdio.h>

#define SQUARE(X) X * X

int main() {

    int a = 5;
    printf("%d", SQUARE(a+1));

}
```

ex08-07.cpp 파일 생성

```c++
#include <stdio.h>

#define SQUARE(X) (X) * (X)

int main() {

    int a = 5;
    printf("%d", 100 / SQUARE(a+1));

}
```

ex08-08.cpp 파일 생성

```c++
#include <stdio.h>

#define SQUARE(X) ((X) * (X))

int main() {

    int a = 5;
    printf("%d", 100 / SQUARE(a+1));

}
```



ex08-09.cpp 파일 생성

```c++
#include <stdio.h>

#define FOR(I,S,E) for (int I =S; I <=E; I++)

int main() {

    FOR(i, 1, 10) {
        printf("%d", i);
    }

}
```



### 8.3 비트 연산

#### 8.3.1 비트 연산자의 종류

& = 비트AND / | = 비트OR / ^ =비트 XOR / ~ =비트 NOT / << = 비트 왼쪽 시프트 연산자 / >> = 비트 오른쪽 시프트 연산자

ex08-10.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    int a=106, b=83;

    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("~a = %d\n", ~a);

}
```



시프트 연산은 비트의 값을 왼쪽, 오른쪽으로 이동시키는 의미

새롭게 생긴 공간은 0으로 채워지고 음수일 때는 1로 채워짐

ex08-11.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    printf("%d\n", 1 << 4);
    printf("%d\n", (-3) << 2);
    printf("%d\n", 31 >> 2);
    printf("%d\n", (-24) >> 3);

}
```



#### 8.3.2 비트 연산자 활용

비트 AND 연산자 : 여러 비트 중 원하는 비트만 남기고 나머지는 0으로 만들고 싶을 때 사용

비트 OR 연산자 + 시프트 : 특정 비트를 1로 설정하고 싶을 때 사용

비트 AND 연산자 + NOT + 시프트 : 특정 비트를 0로 설정하고 싶을 때 사용

비트 XOR 연산자 :  비트를 뒤집을 때 사용 / swap으로 활용 가능



### 8.4 파일 입출력

#### 8.4.1 스트림

스트림 : 데이터가 지나다니는 통로

#### 8.4.2 파일 입출력

ex08-12cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    FILE *in;
    in = fopen("input.txt", "r");

    int n;
    fscanf(in, "%d", &n);
    printf("&d\n", n);

}
```



ex08-13.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    FILE *in;
    FILE *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    int n;
    fscanf(in, "%d", &n);
    fprintf(out, "&d\n", n);

}
```



ex08-14.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    FILE *in;
    FILE *out;
    in = fopen("intput.txt", "r");
    out = fopen("output.txt", "w");

    if ( in == NULL) {
        printf("파일을 여는 데 실패 했습니다. \n");
    }

    else {
        int n;
        fscanf(in, "%d", &n);
        fprintf(out, "&d\n", n);
    }

    if (in != NULL) fclose(in);
    if (out != NULL) fclose(out);
    

}
```



ex08-15.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    FILE *in;
    in = fopen("intput.txt", "r");

    char ch;
    while (fscanf(in, "%c", &ch) != EOF) {
        printf("%c", ch);
    }
    

}
```



### 8.5 유용한 함수들

#### 8.5.1 getchar, putchar, gets, puts - 문자와 문자열 입출력

getchar, putchar : char형 문자 한글자를 입력받거나 출력

ex08-16.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    char ch;
    ch = getchar();
    putchar(ch);
    
}
```

ex08-17.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    char ch;
    
    while (true) {
        ch = getchar();
        if (ch == '\n') break;
        putchar(ch);
    }
    
}
```



gets : 엔터 키가 나올 때까지 입력을 받는 함수

c++에서는 보안상 gets대신 fgets 사용 / fgets는 원래 파일에서 한 줄을 받아오는 역할이지만 표준스트림을 인자로 넣어주면 가능

puts : 문자열을 출력

ex08-18.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    char str[20];
    
    fgets(str, 20, stdin);
    puts(str);
    
}
```



#### 8.5.2 sscanf와 sprintf - 문자열 스트림 입출력

sscanf, sprintf : 문자열을 스트림으로 사용하여 입출력

sprinf : 다른 자료형의 값을 문자열을 바꿀 때 사용

sprintf : 문자열을 다른 자료형으로 바꿀 때 사용

ex08-19.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    char sa[] = "123";
    int a;

    sscanf(sa, "%d", &a);
    printf("%d", a);
    
}
```

ex08-20.cpp 파일 생성

```c++
#include <stdio.h>
#include <string.h>

int main() {

    char sa[10];
    int a;

    printf("정수 입력 : ");
    scanf("%d", &a);

    sprintf(sa, "%d", &a);

    int len = strlen(sa);
    printf("%d은(는) %d 자리 수입니다.", a, len);
    
}
```



#### 8.5.3 rand와 time - 난수 발생과 현재 시각 얻어오기

rand : 난수 발생

ex08-21.cpp 파일 생성

```c++
#include <stdio.h>
#include <stdlib.h>

int main() {

    for (int i=1; i <=5; i++)
        printf("%d\n", rand());
    
}
```

ex08-22.cpp 파일 생성

```c++
#include <stdio.h>
#include <stdlib.h>

int main() {

    for (int i=1; i <=5; i++)
        printf("%d\n", rand() % 10 + 1);
    
}
```



time : 현재 시각 -> rand()의 seed 값으로 자주 활용

srand : 시드 값 설정

ex08-23.cpp 파일 생성

```c++
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    for (int i=1; i <=5; i++)
        printf("%d\n", rand() % 10 + 1);
    
}
```



#### 8.5.4 exit - 프로그램 종료하기

ex08-24.cpp 파일 생성

```c++
#include <stdio.h>


int main() {

    int sum=0;

    for (int i =1; i<=5; i++) {
        int n;
        scanf("%d", &n);
        if (n < 0) {
            printf("INPUT ERROR\n");
            return 0;
        }
        sum += n;
    }

    printf("합 : %d\n", sum);
    
}
```

 

exit : 언제 어디서든 프로그램 바로 종료 가능

ex08-25.cpp 파일 생성

```c++
#include <stdio.h>
#include <stdlib.h>

int getSum() {
    int sum=0;

        for (int i =1; i<=5; i++) {
            int n;
            scanf("%d", &n);
            if (n < 0) {
                printf("INPUT ERROR\n");
                exit(0);
            }
            sum += n;
        }
}

int main() {

    printf("합 : %d\n", getSum());
    
}
```

