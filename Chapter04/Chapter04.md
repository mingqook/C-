## 4. 제어문

### 4.1 if문으로 경우 나누기

#### 4.1.1 if문

ex04-01.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;
    printf("숫자 입력 : ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("n은 짝수 입니다.\n");
    }
}
```

ex04-02.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;
    printf("숫자 입력 : ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("n은 짝수 입니다.\n");
    }

    if (n% 2 == 1) {
        printf("n은 홀수 입니다.\n");
    }
}
```



#### 4.1.2 if-else

ex04-03.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;

    printf("숫자 입력 : ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("n은  짝수입니다.\n");
    }
    else {
        printf("n은 홀수입니다.\n");
    }
}
```



#### 4.1.3  else if

ex04-04.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;

    printf("숫자 입력 : ");
    scanf("%d", &n);

    if (n > 0) {
        printf("n은 양수입니다.\n");
    }
    else if (n == 0){
        printf("n은 0입니다.\n");
    }
    else {
        printf("n은 음수입니다.\n");
    }
}
```

ex04-05.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int score;

    printf("점수입력 : ");
    scanf("%d", &score);

    if (score >= 90) {
        printf("A\n");
    }
    else if (score >= 80){
        printf("B\n");
    }
    else if (score >= 70){
        printf("C\n");
    }
    else if (score >= 60){
        printf("D\n");
    }
    else {
        printf("F\n");
    }
}
```



### 4.2 if문 심화

#### 4.2.1 중첩 if문

ex04-06.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);
    if (a > b){
        if (b > c){
            printf("%d, %d, %d", a, b, c);
        }
        else {
            if (a > c) {
                printf("%d, %d, %d", a, c, b);
            }
            else {
                printf("%d, %d, %d", c, a, b);
            }
        }
    }
    else {
        if (a > c) {
            printf("%d, %d, %d", b, a, c);
        }
        else {
            if (b > c) {
                printf("%d, %d, %d", b, c, a);
            }
            else {
                printf("%d, %d, %d", c, b, a);
            }
        }
    }
}
```



#### 4.2.2 중첩 if문의 관점으로 본 else if

#### 4.2.3 if문과 여러가지 코딩 스타일

if 문을 비롯한 제어문 안의 내용물이 한 문장일 때(세미콜론이 한 개 일 때)는 중괄호를 생략할 수 있음

ex04-07.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);
    if (a > b){
        if (b > c) printf("%d %d %d\n", a, b, c);
        else if (a > c) printf("%d %d %d\n", a, c, b);
        else printf("%d %d %d\n", c, a, b);
    }
    else {
        if (a > c) printf("%d %d %d\n", b, a, c);
        else if (b > c) printf("%d %d %d\n", b, c, a);
        else printf("%d %d %d\n", c, b, a);
    }
}
```



### 4.3 switch 문

switch문은 한 변수가 가지는 값에 따라 경우를 여러 개로 나누는 제어문

ex04-8.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int choice;

    printf("새 게임 : 1 \n");
    printf("불러오기 : 2 \n");
    printf("설정 : 3 \n");
    printf("크레딧 : 4 \n");

    scanf("%d", &choice);

    if (choice == 1) printf("새 게임.\n");
    else if (choice == 2) printf("불러오기.\n");
    else if (choice == 3) printf("설정.\n");
    else if (choice == 4) printf("크레딧.\n");
    else printf("잘못 입력하셨습니다.\n");
}
```

ex04-09.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int choice;

    printf("새 게임 : 1 \n");
    printf("불러오기 : 2 \n");
    printf("설정 : 3 \n");
    printf("크레딧 : 4 \n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("새 게임.\n");
            break;
        case 2:
            printf("불러오기.\n");
            break;
        case 3:
            printf("설정.\n");
            break;
        case 4:
            printf("크레딧.\n");
            break;
        default:
            printf("잘못 입력하셨습니다. \n");
            break;
    }
}
```

ex04-10.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int choice;

    printf("새 게임 : 1 \n");
    printf("불러오기 : 2 \n");
    printf("설정 : 3 \n");
    printf("크레딧 : 4 \n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("새 게임.\n");
        case 2:
            printf("불러오기.\n");
        case 3:
            printf("설정.\n");
        case 4:
            printf("크레딧.\n");
        default:
            printf("잘못 입력하셨습니다. \n");
    }
}
```

case에는 변수가 아닌 상수만 가능

swtich문에 집어넣는 변수는 정수형이거나 enum이어야 함



### 4.4 goto문

goto문 사용 시 명령이 실행되는 순서를 마음대로 변경 가능

레이블 : 원하는 레이블 이름을 쓰고 콜론(:)을 붙이면 잘못 입력했을 때 goto문을 통해 해당 레이블이 있는 줄로 돌아옴

ex04-11.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int choice;

MAKE_CHOICE:
    printf("새 게임 : 1 \n");
    printf("불러오기 : 2 \n");
    printf("설정 : 3 \n");
    printf("크레딧 : 4 \n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("새 게임.\n");
            break;
        case 2:
            printf("불러오기.\n");
            break;
        case 3:
            printf("설정.\n");
            break;
        case 4:
            printf("크레딧.\n");
            break;
        default:
            printf("잘못 입력하셨습니다. \n");
            goto MAKE_CHOICE;
            break;
    }
}
```



### 4.5 While문으로 반복하기

#### 4.5.1 while문

ex04-12.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int i=1;

    while (i<=10) {
        printf("%d ", i);
        i++;
    }
}
```

ex04-13.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int i=1;

    while (true) {
        printf("%d ", i);
        i++;
    }
}
```



#### 4.5.2 do-while문

명령을 먼저 실행하고 마지막에 조건을 확인

ex04-14.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int i=1;

    do {
        printf("%d ", i);
        i++;
    } while (i<=10);
}
```

ex04-15.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;

    do {
        printf("제발 0을 입력해주세요.\n");
        scanf("%d", &n);
    } while (n !=0);

    printf("드디어 0을 입력하셨군요.\n");
}
```



### 4.6 for문으로 반복하기

ex04-16.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;

    printf("자연수 입력 : ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <=n; i++){
        sum += i;
    }

    printf("1부터 %d 까지의 합 : %d\n", n, sum);

}
```



### 4.7 for문 심화

#### 4.7.1 조건 생략하기

for문의 초기 조건, 반복 조건, 증가/감소 세 부분 중 하나 이상은 생략 가능

ex04-17.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;

    printf("자연수 입력 : ");
    scanf("%d", &n);

    for (; n>=1; n--){
        printf("%d ", n);
    }

}
```

ex04-18.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    for (int i =1 ; ; i++){
        printf("%d ", i);
    }
}
```



#### 4.7.2 두 개 이상의 조건 사용하기

ex04-19.cpp 파일 생성

```c++
#include <stdio.h>

int main() {

    int n;
    printf("자연수 입력 : ");
    scanf("%d", &n);

    int i, pow;
    for (i=1, pow=1; i <=n; i++, pow *=2);
    printf("2의 %d 제곱근은 %d\n", n, pow);

}
```



#### 4.7.3 break와 continue: 반복문 조작하기

break를 사용하면 for문 바깥으로 즉시 탈출 가능, while문에서도 사용 가능

ex04-20.cpp 파일 생서

```c++
#include <stdio.h>

int main() {

    for (int i = 1; ; i++) {
        int k;
        scanf("%d", &k);
        if (k ==0) {
            break;
        }
        printf("%d번째 입력 결과 : %d\n", i, k);
    }

}
```



continue는 현재 루프를 건너뛰고 바로 다음 루프로 넘어감

for문에서는 continue를 만나면 증가/감소 파트가 실행되고 나서 다음 루프로 넘어감

ex04-21.cpp 파일 생성

```c++
#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    for (int i =1; i <=n; i++) {
        if (i % 3 == 0) continue;
        printf("%d \n", i);
    }


}
```



#### 4.7.4 중첩 for문

ex04-22.cpp 파일 생성

```c++
#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    for (int i =1; i<=n; i++){
        for (int j=1; j<=n; j++) {
            printf("*");
        }
        printf("\n");
    }
}
```

ex04-23.cpp 파일 생성

```c++
#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    for (int i =1; i<=n; i++){
        for (int j=1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
```

