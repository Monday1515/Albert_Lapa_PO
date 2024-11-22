#include <iostream>
using namespace std;

class Pojazd {
    public:
    void przyspiesz() {
        cout << "This car is accelerating...\n";
    }
};
class Samochod : public Pojazd {
    public:
    void car() {
        przyspiesz();
        cout << "Lets see how good this cars acceleration is.\n";
    };
};
class ElektrycznySamochod : public Samochod {
    public:
    void przyspiesz() {
        car();
        cout << "This car is accelerating very quickly. It must be electric!\n";
    }
};

int main() {
    ElektrycznySamochod Rivian;
    Rivian.przyspiesz();
}