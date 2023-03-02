#include <iostream>
using namespace std;


struct Person {
    int age;
    virtual ~Person() {}
    void Eat() {
        cout << "먹는다.." << endl;
    }
};

struct Student : virtual Person {
    void Study() {
        cout << "공부한다.." << endl;
    }
};

struct Worker : virtual Person {
    void Work() {
        cout << "일한다.." << endl;
    }
};

struct Researcher : Student, Worker {

};

int main() {

   Researcher r;
   r.age = 20;

   cout << r.age << endl;
   cout << r.Student::age << endl;
   cout << r.Worker::age << endl;
   cout << r.Person::age << endl;

   r.Eat();

}