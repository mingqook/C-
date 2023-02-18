## 3. 입력받기

### 3.1 scanf 사용하기

printf : 출력 / scanf : 입력

ex03-1.cpp 파일 생성

```c++
#include <stdio.h>

int main() {
    int a, b;

    scanf("%d%d", &a, &b);
    printf("%d + %d = %d\n", a, b, a+b);
}
```



### 3.2 scanf의 서식 지정자

%d : 정수 / $c : 문자 / %f : 실수 / %lf : double



### 3.3 scanf 함수 관련 보안 문제

scanf는 '버퍼 오버플로'라는 보안상의 취약점 존재

버퍼 오버플로 : 예상보다 긴 입력이 들어 왔을 때 입력받고자 하는 변수의 범위를 벗어나 엉뚱한 변수의 값이 바뀔 수 있는 현상

scanf_s : scanf의 버퍼 오버플로 문제를 방지하기 위해 입력받을 최대 글자 수를 지정