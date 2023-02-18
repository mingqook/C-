## 6. 함수

### 6.1 함수의 정의와 호출

함수들이 정의도어 있는 헤더 파일을 인클루드만 하면 함수를 사용할 수 있음



### 6.2 함수를 만들어 보자!

ex06-01.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int itemCnt = 0;
    int money = 100;

    itemCnt++;
    money -= 10;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);

    itemCnt++;
    money -= 10;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);


}
```



void -> 리턴 값이 없다

ex06-02.cpp 파일 생성

```c++
#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem() {
    itemCnt++;
    money -= 10;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);
}

int main() {

    buyIem();

    buyIem();


}
```



ex06-03.cpp

```c++
#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem(int cost) {
    itemCnt++;
    money -= cost;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);
}

int main() {

    buyIem(30);

    buyIem(40);


}
```



함수의 parameter는 모두 개별로 타입 지정 필요

ex06-04.cpp 파일 생성

```c++
#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem(int cost, int cnt) {
    itemCnt += cnt;
    money -= cost;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);
}

int main() {

    buyIem(30, 5);

    buyIem(50, 7);


}
```



### 6.3 변수의 스코프, 지역 변수와 전역 변수

스코프 -> 변수가 유효한 범위

#### 6.3.1 블록 스코프

블록 -> 중괄호 안에 여러 줄의 코드를 묶은 것

한 블록 안에 선언된 변수는 그 블록 내에서만 사용 가능

변수의 이름이 같아도 선언된 스코프가 다르면 에러가 나지 않고 서로 다른 변수로 인식 -> 같은 스코프 내에서는 같은 이름의 변수를 여러개 만들 수 없음



#### 6.3.2 함수 스코프

지역 변수 -> 함수 안에서 선언된 변수

전역 변수 -> 전역 스코프에 속해 있음

모든 함수에서는 전역 스코프에 접근 가능, 함수의 지역 변수 중에 전역 변수와 이름이 같은 변수가 있을 때는 전역 변수에 접근 불가능



### 6.4 함수의 반환

ex06-05.cpp 파일 생성

```c++
#include <stdio.h>

int plus(int a, int b) {
    return a + b;

}

int main() {
    int sum = plus(3, 5);

    printf("%d\n", sum);
}
```



void 함수는 리넡ㄴ 값이 없으므로 retrun 문이 없어도 함수가 끝까지 실행된 후 호출되었던 지점으로 돌아감

void가 아닌 함수에서 return문이 없다면 함수의 끝에 도달했을 때 컴파일 에러를 뱉거나 자동으로 0을 리턴

main 함수는 정상적으로 종료 시 0을 리턴 그렇지 않으면 이외의 값을 리턴

ex06-06.cpp 파일 생성

```c++
#include <stdio.h>

int noMeaning() {
    printf("first \n");
    return 1;
    printf("second \n");
    return 2;
}

int main() {
    int ret = noMeaning();

    printf("%d\n", ret);
}
```



ex06-07.cpp 파일 생성

```c++
#include <stdio.h>

void noMeaning() {
    printf("first \n");
    return;
    printf("second \n");
    return;
}

int main() {
    noMeaning();
}
```



ex06-08.cpp 파일 생성

```c++\
#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem(int cost) {
    itemCnt++;
    money -= cost;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);
}

int main() {

    buyIem(50);

    buyIem(70);


}
```



ex06-09.cpp 파일 생성

```c++
#include <stdio.h>

int itemCnt = 0;
int money = 100;

int buyIem(int cost) {

    if (money < cost) {
        return -1;
    }

    itemCnt++;
    money -= cost;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);
    return 0;
}

int main() {

    buyIem(50);
    int result = buyIem(70);

    if (result == -1) {
        printf("잔액이 부족합니다! \n");
        printf("    아이템 개수 : %d\n", itemCnt);
        printf("    잔액: %d\n", money);
    }

}
```



### 6.5 Call-by-value, Call-by-address, Call-by-reference

call-by-value -> 함수를 호출 할 때 변수에 들어 있는 "값"이 함수에 복사되는 형태로 전달

ex06-10.cpp 파일 생성

```c++
#include <stdio.h>

void swap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);

    swap(a, b);

    printf("a=%d, b=%d\n", a, b);
}
```



call-by-adress -> 함술르 호출 할 대 변수의 주소를 전달

ex06-11.cpp 파일 생성

```c++
#include <stdio.h>

void swap(int *px, int *py) {
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);

    swap(&a, &b);

    printf("a=%d, b=%d\n", a, b);
}
```



레퍼런스 변수 -> 변수에 별명을 붙이는 것, 레퍼런스 변수는 선언과 동시에 특정 변수를 가르켜야 함

위 두방법과는 다르게 값의 복사가 일어나지 않음

x,y를 a,b의 별칭으로 설정 

call-by-reference -> 참조에 의한 호출,  C++에서만 가능

ex06-12.cpp

```c++
#include <stdio.h>

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);

    swap(a, b);

    printf("a=%d, b=%d\n", a, b);
}
```



### 6.6 프로토타입(함수 원형)

ex06-13.cpp 파일 생성

```c++
#include <stdio.h>

void walk(int distance) {
    printf("%dcm 앞으로 전진했습니다.\n", distance);
}

void rotate(int angle) {
    printf("%d도 회전했습니다.\n", angle);
}

void walkSquare() {
    for (int i = 1; i <=4; i++) {
        walk(10);
        rotate(90);
    }
}

int main() {
    walkSquare();
}
```



컴파일러가 코드를 읽을 때는 첫 줄부터 시작해 아래로 읽음 -> 호출되는 함수가 미리 정의되어 있지 않으면 에러 발생

프로토타입 -> 컴파일러에게 이런 특정 함수가 있다는 정보만 주고 함수의 정의는 나중으로 빼는 것

프로토타입에서는 매개변수의 자료형만 적고 이름을 적어주지 않아도 됨

ex06-14.cpp 파일 생성

```c++
#include <stdio.h>

void walk(int distance);
void rotate(int angle);
void walkSquare();

int main() {
    walkSquare();
}

void walk(int distance) {
    printf("%dcm 앞으로 전진했습니다.\n", distance);
}

void rotate(int angle) {
    printf("%d도 회전했습니다.\n", angle);
}

void walkSquare() {
    for (int i = 1; i <=4; i++) {
        walk(10);
        rotate(90);
    }
}
```



### 6.7 재귀함수

재귀 함수 -> 함수 안에 자기 자신이 다시 들어가는 함수

ex06-15.cpp 파일 생성

```c++
#include <stdio.h>

void rec() {
    printf("rec() 호출됨 \n");
    rec();
}

int main() {
    rec();
}
```



ex06-16.cpp 파일 생성

```c++
#include <stdio.h>

void rec(int n) {
    printf("n = %d\n", n);
    rec(n + 1);
}

int main() {
    rec(1);
}
```



ex06-17.cpp 파일 생성

```c++
#include <stdio.h>

void rec(int n) {

    if (n > 5) {
        return;
    }
    
    printf("n = %d\n", n);
    rec(n + 1);
}

int main() {
    rec(1);
}
```



ex06-18.cpp 파일 생성

```c++
#include <stdio.h>

int fact(int n) {
    if (n ==1) return 1;
    return n * fact(n-1);
}

int main() {
    int n;

    printf("정수 입력 : ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, fact(n));
}
```



### 6.8 배열을 매개변수로 넘기기

#### 6.8.1 일차원 배열 매개변수

ex06-19.cpp 파일 생성

```c++
#include <stdio.h>

void printArr(int parr[4]) {
    for (int i=0; i<4; i++) {
        printf("%d ", parr[i]);
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    printArr(arr);

}
```



배열이 인수로 들어갈 때는 배열 자체가 복사되는 것이 아니라 arr의 값이 복사되는 것, 배열의 모든 칸을 일일이 복사해서 call-by-value가 아니고 call-by-address 형태

ex06-20.cpp 파일 생성

```c++
#include <stdio.h>

void printArr(int parr[4]) {
    printf("parr의 값 : %d\n", parr);
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    printf("arr의 값 : %d\n", arr);
    printArr(arr);

}
```



ex06-21.cpp 파일 생성

```C++
#include <stdio.h>

void printArr(int parr[4]) {
    for (int i=0; i<4; i++) {
        parr[i]++;
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    printArr(arr);
    for (int i =0; i<4; i++) {
        printf("%d ", arr[i]);
    }

}
```

parr이 배열처럼 생겼어도 내부적으로는 그저 int를 가리키는 포인터이기 떄문에 컴파일러 입장에서는 배열의 칸수는 중요하지 않기 때문에 생략 가능



#### 6.8.2 이차원 배열 매개변수