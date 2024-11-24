#include <iostream>
using namespace std;

class Pracownik {

protected:
    string stanowisko = "Teacher";
    float wynagrodzenie = 28.1;
}; // jakis konstruktor? destruktor? metoda (ew. czyxto) wirtualna pokazDane()?

class Administracja : protected Pracownik {
    public:            // tutaj też nie widać konstruktora i destruktora

        string getPositionAdm() {
            return stanowisko;
        }
        float getSalary() {
            return wynagrodzenie;
        }

        void pokazDane() {
            cout << "Administracja: " << stanowisko << ", " << wynagrodzenie << endl;
        }
};

class Nauczyciel : protected Pracownik {
    public:    // j.w.
    
        void pokazDane() {
            cout << "Nauczyciel: " << stanowisko << ". Na wiecej nie mam uprawnien ):" << endl;
        }
};

int main() {

    Administracja szefu; // proszę tworzyć obiekty także w pamięci dynamicznej
    szefu.pokazDane();

    Nauczyciel kamil;
    kamil.pokazDane();

}
