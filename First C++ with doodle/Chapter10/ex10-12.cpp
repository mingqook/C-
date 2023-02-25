#include <iostream>
using namespace std;

class Color {
    public:
        Color() : r(0), g(0), b(0), id(idCounter++) {}
        Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {}

        float GetR() {
            return r;
        }
        float GetG() {
            return g;
        }
        float GetB() {
            return b;
        }
        int GetId() {
            return id;
        }

        static Color MixColors(Color a, Color b) {
            return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2)
        }

    private:
        static int idCounter;
        int id;
        float r;
        float g;
        float b;
}

int Color::idCounter=1;

int main() {
    Color red = Color(1,0,0);
    Color blue = Color(0,0,1);
    Color purple = Color::MixColors(red, blue);

    cout << red.GetId() << endl;
    cout << blue.GetId() << endl;
    cout << purple.GetId() << endl;
}