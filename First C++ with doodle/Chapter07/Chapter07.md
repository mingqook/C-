## 7. 구조체

### 7.1 typedef

typedef -> 새로운 자료형을 정의할 수 있게 해주는 기능, 기존 자료형에 별칭을 붙일 수 있음

typedef의 장점 2가지

* 긴 자료형 이름을 편리한 이름으로 줄일 수 있음
* 변수가 어떤 정보를 저장하는지 좀 더 분명히 드러남



### 7.2 구조체 만들기

#### 7.2.1 구조체 만들기

구조체 : 여러 변수를 한꺼번에 묶어서 만든 새로운 자료형

멤버 변수 : 한 구조체에 속한 변수들

ex07-01.cpp 파일 생성

```c++
#include <stdio.h>

int main() {

    struct
    {
        float x, y;
    } pos;
    pos.x = 1.5;
    pos.y = 2.2;

    printf("좌표 : (%f, %f)\n", pos.x, pos.y);

}
```

C++에서는 중괄호를 사용해서 멤버 변수에 값을 넣을 수 있음



#### 7.2.2 구조체 타입 정의하기

한 구조체 안에 모두 같은 자료형의 멤버가 들어갈 필요는 없음

변수 선언 규칙에 맞게만 선언하면 어떤 형태의 변수든 집어넣을 수 있음



#### 7.2.3 구조체 활용

ex07-02.cpp 파일 생성

```c++
#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[100];
    int cost;
};


int main() {

    ProductInfo myProduct = {4797283, "제주 한라봉", 19900};

    printf("상품 번호 : %d\n", myProduct.num);
    printf("상품 이름 : %s\n", myProduct.name);
    printf("상품 가격 : %d원\n", myProduct.cost);

}
```



### 7.3 구조체와 메모리

ex07-03.cpp 파일 생성

```c++
#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[100];
    int cost;
};


int main() {

    ProductInfo myProduct = {4797283, "제주 한라봉", 19900};

    printf("%d\n", sizeof(myProduct));
    printf("%d\n", &myProduct);
    printf("%d\n", &myProduct.num);
    printf("%d\n", myProduct.name);
    printf("%d\n", &myProduct.cost);

}
```



ex07-04.cpp 파일 생성

```c++
#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[101];
    int cost;
};


int main() {

    ProductInfo myProduct = {4797283, "제주 한라봉", 19900};

    printf("%d\n", sizeof(myProduct));
    printf("%d\n", &myProduct);
    printf("%d\n", &myProduct.num);
    printf("%d\n", myProduct.name);
    printf("%d\n", &myProduct.cost);

}
```

구조체 정렬 -> 구조체 멤버 변수의 주솟값을 해당 멤버 변수 크기의 배수가 되게 맞추려는 경향으로 인해 비효율적인 여분의 공간이 남을 수 있는 현상, 메모리가 낭비되는 공간이 생길 수도 있지만 특정 시스템에서는 멤버 변수들이 모두 붙어있으면 실행 효율이 낮아질 수 있음



### 7.4 구조체 변수 가리키기

ex07-05.cpp 파일 생성

```c++
#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[101];
    int cost;
};


int main() {

    ProductInfo myProduct = {4797283, "제주 한라봉", 19900};
    ProductInfo *ptr_product = &myProduct;

    printf("상품 번호 : %d\n", (*ptr_product).num);
    printf("상품 이름 : %s\n", (*ptr_product).name);
    printf("상품 가격 : %d원\n", (*ptr_product).cost);

}
```



"->" 기호 : 구초체 포인터가 가리키는 구조체 변수의 멤버에 접근할 때 활용

ptr_prodcut -> num == (*ptr_product).num

ex07-06.cpp 파일 생성

```c++
#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[101];
    int cost;
};


int main() {

    ProductInfo myProduct = {4797283, "제주 한라봉", 19900};
    ProductInfo *ptr_product = &myProduct;

    printf("상품 번호 : %d\n", ptr_product -> num);
    printf("상품 이름 : %s\n", ptr_product -> name);
    printf("상품 가격 : %d원\n", ptr_product -> cost);

}
```

 

구조체 변수의 멤버에 접근할 때는 마침표(.) 연산자 활용

구조체 포인터가 가리키는 구조체 변수의 멤버에 접근할 때는 화살표(->) 연산자 활용

구조체 멤버 중에 포인터가 있을 때, 해당 포인터가 가르키는 변수에 접근하고 싶을 때는 괄호 없이 앞에 별표를 붙이면 됨



ex07-07.cpp 파일 생성

```c++
#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[101];
    int cost;
};

void productSwap(ProductInfo *a, ProductInfo *b) {
    ProductInfo tmp = *a;
    *a = *b;
    *b = tmp;

}

int main() {

    ProductInfo myProduct = {4797283, "제주 한라봉", 19900};
    ProductInfo yourProduct = {4797284, "성주 꿀참외", 1000};
    productSwap(&myProduct, &yourProduct);

    printf("상품 번호 : %d\n", myProduct.num);
    printf("상품 이름 : %s\n", myProduct.name);
    printf("상품 가격 : %d원\n", myProduct.cost);

}
```



### 7.5 구조체와 함수

#### 7.5.1 구조체 매개변수의 Call-by-value와 Call-by-address

ex07-08.cpp 파일 생성

```c++
#include <stdio.h>

struct Time
{
    int h, m, s;
};

int totalSec(Time t) {
    return 60*60*t.h + 60*t.m + t.s;
}


int main() {

    Time t = {1, 22, 48};

    printf("%d\n", totalSec(t));

}
```



구조체 변수에 다른 구조체 변수를 대입하면 멤버들이 모두 복사되는 데 이 때 call-by-value로  전달이 되기 때문에 구조체의 크기가 커지게 되면 복사가 많이 일어나 프로그램의 효율이 떨어짐

(크기가 큰) 구조체를 다른 함수로 넘길 때는 call-by-address를 활용하는 것이 선호 -> 넘겨지는 것이 주솟값이기 때문에 함수 호출이 가벼워짐

ex07-09.cpp 파일 생성

```c++
#include <stdio.h>

struct Time
{
    int h, m, s;
};

int totalSec(Time *t) {
    return 60*60*t->h + 60*t->m + t->s;
}


int main() {

    Time t = {1, 22, 48};

    printf("%d\n", totalSec(&t));

}
```



####  7.5.2 구조체에 함수 집어넣기

멤버 함수 : 멤버 변수 처럼 구조체 안에 들어간 함수

ex07-10.cpp 파일 생성

```c++
#include <stdio.h>

struct Time
{
    int h, m, s;
    int totalSec() {
        return 60*60*h + 60*m + s;
    }
};




int main() {

    Time t = {1, 22, 48};

    printf("%d\n", t.totalSec());

}
```

멤버 함수를 만들더라도 구조체의 크기는 변하지 않음

구조체 안에 함수가 포함되었더라도 실제 동작은 ex07-09.cpp 파일의 동작과 동일하게 일어남

