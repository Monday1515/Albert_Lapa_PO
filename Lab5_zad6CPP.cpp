#include <iostream>
using namespace std;

// A class is abstract if it has at least one pure virtual function.
class Pojazd {
    protected:
    string marka = "Toyota";
    string model = "Corolla";

    private:
    int rok = 2003;

    public:

    virtual void przyspiesz() = 0;
    void zatrzymaj() {

    }
};

class Samochod : private Pojazd {
    public:
    string getBrand() {
        return marka;
    }
    string getModel() {
        return model;
    }
    // rok variable is not accessible from Pojazd class
    // int getYear() {
    //     return rok;
    // }
    void przyspiesz() {
        cout << marka << " " << model << " is accelerating...\n";
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