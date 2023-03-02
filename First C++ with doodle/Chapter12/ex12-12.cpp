#include <iostream>
using namespace std;


struct Animal {
    float xpos = 1;
    float ypos = 2;
};

struct FlyingAnimal : public Animal {
    float zpos = 3;
};

void printAnimals(Aniaml *a, int n) {
    for (int i=0; i < n; i++) {
        cout << "(" << a[i].xpos << ", " << a[i].ypos << ")" << endl;
    }
};

int main() {

    FlyingAnimal *arr = new FlyingAnimal[5];

    printAnimals(arr, 5);
    delete[] arr;

}