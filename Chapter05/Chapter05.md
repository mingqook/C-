## 5. 배열과 포인터

### 5.1 배열

배열(array) : 서로 같은 자료형의 변수를 특정 개수만큼 나열해 놓은 것

#### 5.1.1 배열의 선언과 사용

ex05-01.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[5] = {1,3,5,7,9};

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);
    printf("%d\n", arr[4]);
}
```

ex05-02.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[5] = {1,3,5,7,9};

    for (int i=0; i<5; i++) {
        printf("%d\n", arr[i]);
    }
}
```

ex05-03.cpp

```c++
#include <stdio.h>

int main() {
    int arr[5] = {1,3,5,7,9};

    for (int i=0; i<sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", arr[i]);
    }
}
```



#### 5.1.2 배열의 초기화

배열을 초기화할 때는 중괄호를 사용

중괄호를 통해서 배열의 값을 대입할 수는 없음

한 배열의 내용물을 다른 배열로 한꺼번에 복사도 불가능 -> 배열의 내용 전체를 복사하려면 for 문 활용 필요

초기화시키는 값인 중괄호 안의 개수만큼의 배열을 만들고 싶을 떄는 [] 안에 숫자를 생략 가능

칸 수를 선언했는데 중괄호 안의 개수보다 클 때는 나머지 칸들은 0으로 채워짐



### 5.2 배열 활용

#### 5.2.1 거꾸로 출력하기

ex05-04.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;
    int arr[1000];

    printf("입력할 숫자의 개수 : ");
    scanf("%d", &n);
    printf("숫자 %d개를 입력하세요 : ", n);
    for (int i=0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = (n-1); i >=0 ; i--) {
        printf("%d ", arr[i]);
    }
}
```



#### 5.2.2 최대 최소 구하기

ex05-05.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;
    int arr[1000];

    printf("입력할 숫자의 개수 : ");
    scanf("%d", &n);
    printf("숫자 %d개를 입력하세요 : ", n);
    for (int i=0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max=arr[0];
    for (int i =1 ; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    printf("최대값 : %d", max);
}
```



#### 5.2.3 짝수의 개수 구하기

ex05-06.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int n;
    int arr[1000];

    printf("입력할 숫자의 개수 : ");
    scanf("%d", &n);
    printf("숫자 %d개를 입력하세요 : ", n);
    for (int i=0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int cnt = 0;
    for (int i =0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cnt++;
        }
    }
    printf("짝수의 개수 : %d\n", cnt);
}
```



### 5.3  다차원 배열

#### 5.3.1 이차원 배열

printf에서 %4d를 사용하면 정수 하나를 출력할 때 4칸의 공간을 확보해서 출력 가능 -> 일정 한격으로 숫자 출력시 유용

ex05-07.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}
```

이차원 배열 초기화할 때 행의 개수는 생략 가능하지만 열의 개수는 생략 불가능



#### 5.3.2 다차원 배열



### 5.4 문자열

#### 5.4.1  문자열의 초기화와 출력

문자열을 초기화할 때는 큰따옴표 활용 가능

문자열 배열은 문자의 개수보다 1만큼 큰 칸 수를 지녀야 함 -> 모든 문자열의 끝에는 null 문자(\0, 문자열의 끝을 알려주는 역할)가 포함되어야 하기 때문, 큰따옴표를 통해 문자열 표기하면 자동으로 맨 끝에 null 문자가 추가

ex05-08.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    char s[] = "Hello, world!";

    printf("%s\n", s);
}
```

%s의 역할 -> 문자열의 첫 문자부터 시작해서 null 문자가 나올때까지 출력

ex05-09.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    char s[5] = {'h','e','l','l','o'};

    printf("%s\n", s);
}
```

문자열 각 칸은 %c로 접근하여 출력 가능

ex05-10.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    char s[] = "mingukkim";

    printf("%c\n", s[0]);
    s[0] = 'M';
    s[3] = 'N';
    printf("%s\n", s);
}
```



#### 5.4.2 문자열 입력받기

ex05-11.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    char s[1000];

    scanf("%s", s);
    printf("%s\n", s);
}
```



#### 5.4.3 문자열 관련 함수

strlen -> 문자열 길이 = Null 문자를 제외한 글자 수(첫 Null 문자가 나오기 직전까지의 글자 수)

ex05-12.cpp 파일 생성

```c++
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000] = "hello";
    int len = strlen(s);

    printf("배열의 칸수 : %d\n", sizeof(s) / sizeof(s[0]));
    printf("문자열의 길이 : %d\n", len);

}
```



strcpy -> 문자열 복사

strncpy -> 최대 n칸만 복사

ex05-13.cpp 파일 생성 (배열에서 배열로 복사)

```c++
#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "hello";
    char s2[100];

    strcpy(s2, s1);
    printf("s1 : %s\n", s1);
    printf("s2 : %s\n", s2);

}
```

ex05-14.cpp 파일 생성 (상수형 문자열을 배열에 삽입)

```c++
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    strcpy(s, "hello");
    printf("s : %s\n", s);

}
```



strcat -> 문자열 연결 = += 연산과 동일, 앞 문자열에 뒤 문자열의 내용을 추가하여 변경

strncat -> 최대 n글자만 복사, 끝에 null 문자가 항상 자동으로 추가, 복사할 수 있는 최대 글자 수는 sizeof(s) - strlen(s) - 1

ex05-15.cpp 파일 생성

```c++
#include <stdio.h>
#include <string.h>

int main() {
    char greeting[100] = "Hello, ";
    char name[100];

    scanf("%s", name);

    strcat(greeting, name);
    strcat(greeting, "!");

    printf("%s", greeting);
}
```



strcmp -> 문자 두 개를 사전 순으로 비교, 앞 문자열과 뒤 문자열이 일치 = 0, 앞 문자열이 뒤 문자열보다 사전순을 빠름 : 음수, 늦음 : 양수

 ex05-16.cpp 파일 생성

```c++
#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "sample";
    char s2[] = "sample";

    if (strcmp(s1, s2) < 0) {
        printf("%s는 %s보다 사전 순으로 빠릅니다.\n", s1, s2);
    }
    else if (strcmp(s1, s2) == 0) {
        printf("%s는 %s와 일치합니다..\n", s1, s2);
    }
    else {
        printf("%s는 %s보다 사전 순으로 늦습니다.\n", s1, s2);
    }
}
```



### 5.5 변수 가리키기 - 포인터

포인터 : 변수를 가리키는 존재

포인터는 변수를 가리키지만 동시에 포인터 자체도 하나의 변수 -> 포인터에는 다른 변수의 주솟값이 저장

변수 이름 앞에 &를 붙이면 해당 변수의 주솟값을 의미

ex05-17.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    printf("%d\n", &a);
}
```



#### 5.5.1 포인터의 사용

포인터 선언은 포인터 이름 앞에 *를 붙이면 됨

ex) int *ptr_a; -> int형 변수를 가리키는 ptr_a 이름을 가진 포인터 생성

ex05-18.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    int *ptr_a;
    ptr_a = &a;

    printf("a의 값 : %d\n", a);
    printf("a의 주솟값 : %d\n", &a);
    printf("ptr_a의 값 : %d\n", ptr_a);

}
```



포인터의 또 다른 기능 -> 현재 가리키고 있는 변수에 접근(역참조) -> 포인터에 저장된 주소로 가서 그 주소에 있는 변수에 저장된 값을 불러오거나 바꿀 수 있음

역참조 역시 포인터 선언과 마찬가지로 *를 활용

ex05-19.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    int *ptr_a;
    ptr_a = &a;

    printf("a의 값 : %d\n", a);
    printf("a의 주솟값 : %d\n", &a);
    printf("ptr_a의 값 : %d\n", ptr_a);
    printf("ptr_a에 저장된 주소에 저장된 값 : %d\n", *ptr_a); ///*ptr_a의 값은 a의 값과 동일

}
```

**포인터에 별표 연산자를 붙이면 포인터가 현재 가리키고 있는 변수와 같은 의미**

ex05-20.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    int *ptr_a;
    ptr_a = &a;
    *ptr_a = 20;

    printf("a =  %d\n", a);
    printf("*ptr_a =  %d\n", *ptr_a);
}
```

ptr = &b -> ptr에 b의 주솟값을 집어 넣겠다 == ptr이 b를 가리키게 하겠다.

*ptr =b  -> ptr이 현재 가리키고 있는 변수에 b의 값을 집어 넣겠다.

ex05-21.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    int b=20;
    int *ptr = &a;
    printf("ptr가 가리키는 변수의 값 =  %d\n", *ptr);
    
    ptr = &b;
    printf("ptr가 가리키는 변수의 값 =  %d\n", *ptr);
}
```



#### 5.5.2  널 포인터

포인터에 어떤 변수의 주솟값 대신 NULL이라는 값을 넣으면 "포인터가 아무것도 가리키고 있지 않다" 의미

널 포인터를 역참조 시 에러 ㅂ라생



#### 5.5.3 더블 포인터 

더블 포인터 : 포인터의 주소를 저장하는 포인터

ex05-22.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    int *ptr_a = &a;
    int **ptr_ptr_a = &ptr_a;

    printf("1. a = %d\n", a);
    printf("2. &a = %d\n", &a);
    printf("3. ptr_a = %d\n", ptr_a);
    printf("4. &ptr_a = %d\n", &ptr_a);
    printf("5. ptr_ptr_a = %d\n", ptr_ptr_a);
    printf("6. *ptr_ptr_a = %d\n", *ptr_ptr_a);
    printf("7. **ptr_ptr_a = %d\n", **ptr_ptr_a);
}
```



### 5.6 배열과 포인터와의 관계

ex05-23.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    printf("&a = %d\n", &a);
    printf("(&a) + 1 = %d\n", (&a) + 1);
    printf("(&a) + 2 = %d\n", (&a) + 2);
}
```

ex05-24.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a=10;
    int *ptr_a = &a;
    printf("ptr_a = %d\n", ptr_a);
    printf("ptr_a + 1 = %d\n", ptr_a + 1);
    printf("ptr_a + 2 = %d\n", ptr_a + 2);
}
```

포인터를 선언할 대 가리키는 자료형을 적어야 하는 이유는 가리키는 대상의 크기를 알아야 그만큼의 바이트 수를 읽어올 수 있고, 포인터에 정수값을 더할 때도 마찬가지로 대상의 크기만큼 곱해서 주솟값을 더해야 함

포인터에 정수를 더하는 연산을 하면 실제로는 가리키는 대상의 크기만큼 곱해져서 더해짐

ex05-25.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i=0; i<10; i++) {
        printf("arr[%d]의 주소 : %d \n", i, &arr[i]);
    }
}
```

**배열의 이름은 배열의 0번 칸의 주솟값과 동일**

**&arr[i] (=&arr[0]+i])는 arr+i와 같은 말이고, arr[i]는 *(arr +i)와 같은 말**

ex05-26.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("arr의 값 : %d \n", arr);
    printf("&arr[0]의 값 : %d \n", &arr[0]);
}
```



**어떤 포인터 ptr이 배열 arr의 0번 칸을 가리키고 있다면 ptr[i]와 arr[i]는 같은 의미**

ex05-27.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr = &arr[0];

    printf("&arr[3]의 값 : %d \n", &arr[3]);
    printf("arr+3의 값 : %d \n", arr+3);
    printf("ptr+3의 값 : %d \n", ptr+3);
    printf("&ptr[3]의 값 : %d \n", &ptr[3]);

    printf("arr[3]의 값 : %d \n", arr[3]);
    printf("*(arr+3)의 값 : %d \n", *(arr+3));
    printf("*(ptr+3)의 값 : %d \n", *(ptr+3));
    printf("ptr[3]의 값 : %d \n", ptr[3]);
}
```



ex05-28.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int *ptr = arr; ptr < arr + 10; ptr++) {
        printf("%d\n", *ptr);
    }
}
```



### 5.7 배열 가리키기 - 배열 포인터

배열 포인터 : 배열을 가리키는 포인터

배열 포인터는 가리키는 대상이 배열 그 자체, 배열의 이름은 가리키는 대상이 배열 전체가 아니라 배열의 한 칸이라는 점이 가장 큰 차이

ex05-29.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[10];
    
    printf("%d\n", &arr);
    printf("%d\n", arr);
    printf("%d\n", &arr[0]);

}
```

&arr[0]와 &arr의 값이 같더라도 "배열의 시작 칸"과 "배열의 주솟값"이라는 의미가 다름

&arr[0]는 가리키는 대상이 말 그대로 arr[0] , &arr은 가르키는 대상이 말 그대로 arr

배열 포인터 선언 시 () 반드시 필요, 그렇지 않으면 포인터 배열이 됨

ex) int (*p_arr)[10] -> 10칸 짜리 int형 배열을 가리키는 p_arr 이름의 포인터

ex05-30.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[3] = {1,2,3};
    int (*p_arr)[3] = &arr;

    for (int i =0; i <3; i++) {
        printf("%d\n", (*p_arr)[i]);
    }

}
```



### 5.8 이차원 배열과 배열 포인터

ex05-31.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    printf("%d\n", &arr[0]);
    printf("%d\n", arr);
    printf("%d\n", &arr[1]);
    printf("%d\n", arr + 1);
    printf("%d\n", &arr[0] + 1);

}
```

ex05-32.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int (*p_row)[4] = &arr[1];

    for (int i=0; i < 4; i++) {
        printf("%d ", (*p_row)[i]);
    }
    printf("\n");

}
```



### 5.9 포인터 배열

포인터 배열 : 포인터들로 이루어진 배열

포인터 배열은 배열 포인터에서 소괄호를 빼서 선언

ex) int *ptr[3] -> int를 가리키는 포인터 3개로 이루어진 ptr 이름의 배열

