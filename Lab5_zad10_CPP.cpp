#include <iostream>
using namespace std;

class Pojazd {
    public:
    void przyspiesz() {
        cout << "This car is accelerating...\n";
    }
};
class Silnikowy : virtual public Pojazd {
    public:
    void internalCombustion() {
        przyspiesz();
        cout << "This car has an internal-combustion engine.\n";
    }
};
class Elektryczny : virtual public Pojazd {
    public:
    void EV() {
        przyspiesz();
        cout << "This car can be charged with electricity.\n";
    }
};
class Hybryda : public Silnikowy, public Elektryczny {
    public:
    void hybrid() {
        internalCombustion();
        EV();
        cout << "This is a hybrid-powertrain car. You'll get an amazing milage with this one!\n";
    }
};

int main() {
    Hybryda Prius;
    Prius.hybrid();
}