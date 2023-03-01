## 12. 상속

### 12.1 상속 기초 

#### 12.1.1 상속의 개념

상속 : 어떤 클래스의 멤버를 다른 클래스에 물려주는 것 -> 상속이 일어나면 부모 클래스의 멤버들을 자식 클래스도 가지게 됨



#### 12.1.2 상속과 접근 제어

public : 클래스 외부에서도 접근 가능

private : 클래스 내부에서만 접근 가능

protected : 클래스 내부와 자식 클래스에서 접근 가능

부모 클래스의 private 멤버들이 자식 클래스에서 접근이 불가능 하지만 상속은 됨 -> 자식 클래스는 부모의 private 멤버들을 가지고는 있지만 접근은 불가능

상속 모드 : 자식 클래스 이름 : 뒤에 붙음(public, protected, private), 상속받은 멤버들의 접근 제어를 제한, 일반적으로 상속 모드는 public을 사용



#### 12.1.3 상속 예제

ex12-01.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Animal {
    public:
        void Breathe() {
            cout << "숨을 쉰다" << endl;
        }
        int age;
};

class Dog : public Animal {
    public:
        void Walk() {
            cout << "걷는다" << endl;
        }
};

class Sparrow : public Animal {
    public:
        void Fly() {
            cout << "난다" << endl;
        }
};

int main() {

    Dog d;
    d.age = 7;
    d.Breathe();
    d.Walk();
    cout << d.age << endl;

    Sparrow s;
    s.age = 2;
    s.Breathe();
    s.Fly();
    cout << s.age << endl;

}
```



### 12.2 상속 관계에서의 생성/소멸자

상속 관계에서는 자식 클래스의 생성자가 호출된다면 반드시 부모 클래스의 생성자도 호출되어야 함

ex12-02.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Base {
    public:
        Base() {
            cout << "Base()" << endl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            cout << "Derived()" << endl;
        }
};


int main() {
    Derived d;
}
```



ex12-03.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Ice {
    public:
        Ice() {
            cout << "Ice()" << endl;
        }
        ~Ice() {
            cout << "~Ice()" << endl;
        }
};

class Pat {
    public:
        Pat() {
            cout << "Pat()" << endl;
        }
        ~Pat() {
            cout << "~Pat()" << endl;
        }
};

class Bingsoo {
    pulibc:
        Bingsoo() {
            cout << "Bingsoo()" << endl;
        }
        ~Bingsoo() {
            cout << "~Bingsoo()" << endl;
        }
    private:
        Ice ice;
};

class PatBingsoo : public Bingsoo {
    public:
        PatBingsoo() {
            cout << "PatBingsoo()" << endl;
        }
        ~PatBingsoo() {
            cout << "~PatBingsoo()" << endl;
        }
    private:
        Pat pat;
};

int main() {
    cout << "=====1==========" << endl;
    PatBingsoo *p = new PatBingsoo;
    cout << "=====2==========" << endl;
    delete p;
    cout << "=====3==========" << endl;
}
```



클래스의 생성자가 호출되는 순간 아래와 같은 순서로 일이 발생

1. 부모 클래스의 생성자 먼저 호출
2. 클래스의 모든 멤버 변수가 생성(멤버 변수들의 생성자 호출)
3. 생성자의 본문 실행



소멸자는 순서가 생성자와 정반대로 일어남

1. 소멸자의 본문이 실행
2. 클래스의 모든 멤버 변수가 소멸(멤버 변수들의 소멸자 호출)
3. 부모 클래스의 소멸자를 마지막에 호출



### 12.3 상속이 필요한 이유(1)

ex12-04.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Image{
    public:
        operator string() {
            return "사진";
        }
};

class TextMessage {
    public:
        TextMessage(int sendTime, string sendName, string text) {
            this -> sendTime = sendTime;
            this -> sendName = sendName;
            this -> text = text;
        }

        int GetSendTime() const { 
            return sendTime;
        }
        string GetSendName() const {
            return sendName;
        }
        string GetText() const {
            return text;
        }
    private:
        int sendTime;
        string sendName;
        string text;
};

class ImageMessage {
    public:
        ImageMessage(int sendTime, string sendName, Image *image) {
            this -> sendTime = sendTime;
            this -> sendName = sendName;
            this -> image = image;
        }

        int GetSendTime() const { 
            return sendTime;
        }
        string GetSendName() const {
            return sendName;
        }
        Image *GetImage() const {
            return image;
        }
    private:
        int sendTime;
        string sendName;
        Image *image;
};


int main() {

    Image *dogImage = new Image;
    TextMessage *hello = new TextMessage(10, "민국", "안녕");
    ImageMessage *dog = new ImageMessage(20, "민국", dogImage);
    
    cout << "보낸 시간 : " << hello -> GetSendTime() << endl;
    cout << "보낸 사람 : " << hello -> GetSendName() << endl;
    cout << "  내용 " << hello -> GetText() << endl;
    cout << endl;

    cout << "보낸 시간 : " << dog -> GetSendTime() << endl;
    cout << "보낸 사람 : " << dog -> GetSendName() << endl;
    cout << "  내용 " << (string)*dog -> GetImage() << endl;
    cout << endl;

    delete dogImage;
    delete hello;
    delete dog;
}
```



ex12-05.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Image{
    public:
        operator string() {
            return "사진";
        }
};

class Message {
    public:
        Message(int sendTime, string sendName) {
            this -> sendTime = sendTime;
            this -> sendName = sendName;
        }
        
        int GetSendTime() const { 
            return sendTime;
        }

        string GetSendName() const {
            return sendName;
        }
    private :
        int sendTime;
        string sendName;
};

class TextMessage : public Message {
    public:
        TextMessage(int sendTime, string sendName, string text)
            : Message(sendTime, sendName) {
            this -> text = text;
        }

        string GetText() const {
            return text;
        }
    private:
        string text;
};

class ImageMessage : public Message {
    public:
        ImageMessage(int sendTime, string sendName, Image *image) 
            : Message(sendTime, sendName) {
            this -> image = image;
        }

        Image *GetImage() const {
            return image;
        }
    private:
        Image *image;
};


int main() {

    Image *dogImage = new Image;
    TextMessage *hello = new TextMessage(10, "민국", "안녕");
    ImageMessage *dog = new ImageMessage(20, "민국", dogImage);
    
    cout << "보낸 시간 : " << hello -> GetSendTime() << endl;
    cout << "보낸 사람 : " << hello -> GetSendName() << endl;
    cout << "  내용 " << hello -> GetText() << endl;
    cout << endl;

    cout << "보낸 시간 : " << dog -> GetSendTime() << endl;
    cout << "보낸 사람 : " << dog -> GetSendName() << endl;
    cout << "  내용 " << (string)*dog -> GetImage() << endl;
    cout << endl;

    delete dogImage;
    delete hello;
    delete dog;
}
```



### 12.4 오버라이딩

#### 12.4.1 멤버 재정의와 정적 바인딩

ex12-06.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Base {
    public:
        int a = 10;
};

class Derived : public Base {
    public:
        int a = 20;
};

int main() {

    Base b;
    Derived d;

    cout << b.a << endl;
    cout << d.a << endl;
    
}
```



자식 클래스에는 Base로부터 상속받은 멤머 a와 고유 멤버 a 2개가 존재 -> 동명인 멤버가 있을 때는 자식에서 선언된 멤버가 부모에서 선언된 멤버보다 우선적으로 인식



ex12-07.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Base {
    public:
        void Print() {
            cout << "From Base!" << endl;
        }
};

class Derived : public Base {
    public:
        void Print() {
            cout << "From derived!" << endl;
        }
};

int main() {

    Derived d;

    d.Print();
    d.Base::Print();
    d.Derived::Print();

}
```



재정의 : 자식 클래스에서 부모 클래스와 똑같은 이름의 멤버를 정의하는 것

부모 클래스 타입을 가리키는 포인터가 자식 클래스의 객체를 가리키는 데는 문제 없음 - 자식 클래스를 부모 클래스로 취급 가능

자식 클래스 포인터가 부모 클래스 객체를 가리킬 수는 없음

정적 바인딩 : 호출마다 어떤 메서드가 실행될 지 컴파일 타임에 정해지는 것



#### 12.4.2 가상 함수, 오버라이딩과 동적 바인딩

동적 바인딩 : 컴파일이 타임이 아닌 런타임에, 프로그램 실행 도중에 메서드를 바인딩 하는 방법

가상 함수 : 부모 클래스의 어떤 메서드를 가상 함수로 설정하면 자식이 그 메서드를 재정의 했을 때 동적 바인딩이 일어남

ex12-08.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Weapon {
    public:
        Weapon(int power) : power(power) {
            cout << "Weapon(int)" << endl;
        }
        virtual void Use() {
            cout << "Weapon::Use()" << endl;
        }
    protected:
        int power;
};

class Sword : public Weapon {
    public:
        Sword(int power) : Weapon(power) {
            cout << "Sword(int)" << endl;
        }

        void User() {
            cout << "Sword::User()" << endl;
            swing(); 
        }
    
    private:
        void swing() {
            cout << "Swing sword" << endl;
        }
};

class Magic : public Weapon {
    public:
        Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
            cout << "Magic(int, int)" << endl;
        }

        void Use() {
            cout << "Magic::Use()" << endl;
            cast();
        }
    
    private:
        void cast() {
            cout << "Cast magic" << endl;
        }
        int manaCost;
}

int main() {

    Sword mySword(10);
    Magic myMagic(15, 7);

    Weapon *currentWeapon;

    currentWeapon = &mySword;
    currentWeapon -> Use();

}
```



오버라이딩 : 부모의 가상 함수를 재정의하는 것 -> 가상 함수의 바인딩에 대해서는 컴파일러가 신경쓰지 않기 때문

부모 클래스의 포인터를 통해 부모 클래스의 가상 함수를 호출한다면 컴파일 시점에는 어떤 함수가 실행될지 결정되지 않고, 런타임에 실제 객체의 타입에 따라 바인딩하게 됨



#### 12.4.3 가상 소멸자

소멸자에서는 메모리 해제 같이 객체가 소멸되면서 해야 할 마무리 작업들이 수행

동적 할당된 객체는 생성될 때는 생성되는 객체의 정확한 타입을 알지만 소멸될 때는 그렇지 못하다는 비대칭성 존재

오버라이딩이 일어날 가능성이 있다면 전부 가상 소멸자를 만들어야 함

가상 함수가 하나라도 포함된 클래스라면 거의 항상 소멸자도 가상으로 만들어야 함 -> 오버라이딩을 사용하겠다는 것은 다형성을 사용하겟다는 것이고, 그런 경우에 부모 클래스의 포인터를 통해 자식 클래스의 객체를 해제하려는 상황이 벌어질 가능성이 매우 높기 때문



### 12.5 상속이 필요한 이유(2)

ex12-09.cpp 파일 생성

```c++
#include <iostream>
using namespace std;


class Image{
    public:
        operator string() {
            return "사진";
        }
};

class Message {
    public:
        Message(int sendTime, string sendName) {
            this -> sendTime = sendTime;
            this -> sendName = sendName;
        }
        virtual ~Message() {

        }
        
        int GetSendTime() const { 
            return sendTime;
        }

        string GetSendName() const {
            return sendName;
        }

        virtual string GetContent() const {
            return "";
        }
    private :
        int sendTime;
        string sendName;
};

class TextMessage : public Message {
    public:
        TextMessage(int sendTime, string sendName, string text)
            : Message(sendTime, sendName) {
            this -> text = text;
        }

        string GetContent() const {
            return text;
        }
    private:
        string text;
};

class ImageMessage : public Message {
    public:
        ImageMessage(int sendTime, string sendName, Image *image) 
            : Message(sendTime, sendName) {
            this -> image = image;
        }

        string GetContent() const {
            return (string)*image;
        }
    private:
        Image *image;
};

void printMessage(Message *m) {
    cout << "보낸 시간 : " << m -> GetSendTime() << endl;
    cout << "보낸 사람 : " << m -> GetSendName() << endl;
    cout << "  내용 " << m -> GetContent() << endl;
    cout << endl;
}

int main() {

    Image *dogImage = new Image;
    TextMessage *hello = new TextMessage(10, "민국", "안녕");
    ImageMessage *dog = new ImageMessage(20, "민국", dogImage);
    
    printMessage(hello);
    printMessage(dog);

    delete dogImage;
    delete hello;
    delete dog;
}
```

가상 함수를 사용했으므로 동적 바인딩이 일어나고, 이 사실을 활용하여 종류에 상관없이 동일한 함수를 호출하여 내용물 출력 가능



ex12-10.cpp 파일 생성

```c++
#include <iostream>
#include <string>
using namespace std;


class Image{
    public:
        operator string() {
            return "사진";
        }
};

class Message {
    public:
        Message(int sendTime, string sendName) {
            this -> sendTime = sendTime;
            this -> sendName = sendName;
        }
        virtual ~Message() {

        }
        
        int GetSendTime() const { 
            return sendTime;
        }

        string GetSendName() const {
            return sendName;
        }

        virtual string GetContent() const {
            return "";
        }
    private :
        int sendTime;
        string sendName;
};

class TextMessage : public Message {
    public:
        TextMessage(int sendTime, string sendName, string text)
            : Message(sendTime, sendName) {
            this -> text = text;
        }

        string GetContent() const {
            return text;
        }
    private:
        string text;
};

class ImageMessage : public Message {
    public:
        ImageMessage(int sendTime, string sendName, Image *image) 
            : Message(sendTime, sendName) {
            this -> image = image;
        }

        string GetContent() const {
            return (string)*image;
        }
    private:
        Image *image;
};

void printMessage(Message &m) {
    cout << "보낸 시간 : " << m.GetSendTime() << endl;
    cout << "보낸 사람 : " << m.GetSendName() << endl;
    cout << "  내용 " << m.GetContent() << endl;
    cout << endl;
}

int main() {

    Image *dogImage = new Image;

    Message *messages[] = {
        new TextMessage(10, "민국", "안녕"),
        new ImageMessage(20, "민국", dogImage),
        new TextMessage(30, "민국", "잘가")
    }
    
    for (Message *m : messages) {
        printMessage(*m);
    }
    
    for (Message *m : messages) {
        delete m;
    }
    
    delete dogImage;

}
```



### 12.6 순수 가상 함수와 추상 클래스

순수 가상 함수 : 순수하게 가상인 함수, 실체가 없음

함수를 선언하고 =0을 붙이면 순수 가상 함수가 됨, 본문이 없으므로 중괄호와 안에 내용물 대신 세미콜론으로 선언을 마침

추상 클래스 : 순수 가상 함수가 하나라도 있는 클래스

추상 클래스를 가지고는 객체를 만들 수 없음 -> 추상 클래스에는 본문이 없는 순수 가상 함수가 최소한 하나 있고, 해당 함수를 호출하는 것 자체가 말이 안됨

ex12-11.cpp 파일 생성

```c++
#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

class Shape {
    public:
        virtual ~Shape() {}
        virtual double GetArea() const =0;
        virtual double Resize(double factor) =0;
};

class Circle : public Shape {
    public:
        Circle(double r) : r(r) {}
        double GetArea() const {
            return r * r * PI;
        }
        void Resize(double factor) {
            r *= factor;
        }

    private:
        double r;
};

class Rectangle : public Shape {
    public:
        Rectangle(double a, double b) : a(a), b(b) {}
        double GetArea() const {
            return a*b;
        }
        void Resize(double factor) {
            a *= factor;
            b *= factor;
        }
    private:
        double a, b;
}


int main() {

    Shape *shapes[]  = {new Circle(1), new Rectangle(1,2)};

    for (Shape *s : shapes) {
        s -> Resize(2);
    }

    for (Shape *s : shapes) {
        cout << s->GetArea() << endl;
    }

    for (Shape *s : shapes) {
        delete s;
    }

}
```



