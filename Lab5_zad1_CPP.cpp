#include <iostream>
using namespace std;

class Pojazd {
    public:

    void przyspiesz() {
        cout << "Accelerating...\n";
    }
    void zatrzymaj() {

    }
};

class Samochod : public Pojazd {
    public:
    void przyspiesz() {
        cout << "Accelerating using internal combustion engine...\n";
    }
};

class Rower : public Pojazd {
    public:
    void przyspiesz() {
        cout << "Accelerating using power of legs muscles...\n";
    }
};

int main() {

    Samochod Corolla;
    Rower Cross;

    Corolla.przyspiesz();
    Cross.przyspiesz();
}