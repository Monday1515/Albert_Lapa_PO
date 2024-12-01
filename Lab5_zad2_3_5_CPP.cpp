#include <iostream>
using namespace std;

// A class is abstract if it has at least one pure virtual function.
class Pojazd {
    protected:
    string marka = "Toyota";
    string model = "Corolla";

    public:
    int rok = 2003;

    virtual void przyspiesz() = 0;
    void zatrzymaj() {

    }
};

class Samochod : protected Pojazd {
    public:
    string getBrand() {
        return marka;
    }
    string getModel() {
        return model;
    }
    int getYear() {
        return rok;
    }
    void przyspiesz() {
        cout << marka << " " << model << " " << rok << " is accelerating...\n";
    }
};

class Rower : public Pojazd {
    public:
    void przyspiesz() {
        cout << "Accelerating using power of legs muscles...\n";
    }
};

int main() {             // kiepska ilustracja polimorfizmu

    Samochod Corolla;   
    Rower Cross;

    Corolla.przyspiesz();
    Cross.przyspiesz();
}
