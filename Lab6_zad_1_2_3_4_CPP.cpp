#include <iostream>
#include <vector>
using namespace std;

class Pojazd {
    public:

    virtual void przyspiesz() {
        cout << "Accelerating...\n";
    }
    virtual void zatrzymaj() {
        cout << "Stopping...\n";
    }
    ~Pojazd() {
        cout << "Destructor called.\n";
    }
};

class Samochod : public Pojazd {
    public:
    void przyspiesz() {
        cout << "Accelerating a 4-wheeler using internal combustion engine... [car]\n";
    }
    void zatrzymaj() {
        cout << "Stopping the car...\n";
    }
};

class Rower : public Pojazd {
    public:
    void przyspiesz() {
        cout << "Accelerating using power of legs muscles... [bike]\n";
    }
    void zatrzymaj() {
        cout << "Stopping the bike...\n";
    }
};

class Motocykl : public Pojazd {
    public:
    void przyspiesz() {
        cout << "Accelerating a 2-wheeler using internal combustion engine... [motorbike]\n";
    }
    void zatrzymaj() {
        cout << "Stopping the motorcycle...\n";
    }
};

class Skuter : public Pojazd {
    public:
    void przyspiesz() {
        cout << "Accelerating a weak 2-wheeler using internal combustion engine... [vespa]\n";
    }
    void zatrzymaj() {
        cout << "Stopping the Vespa...\n";
    }
};

int main() {
    vector<Pojazd*> pojazdy = {new Samochod(), new Rower(), new Motocykl(), new Skuter()};
    for (Pojazd* pojazd : pojazdy) {
        pojazd->przyspiesz();
        pojazd->zatrzymaj();
    }
}