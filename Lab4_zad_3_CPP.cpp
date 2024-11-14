#include <iostream>
using namespace std;

class Pracownik {

protected:
    string stanowisko = "Teacher";
    float wynagrodzenie = 28.1;
};

class Administracja : protected Pracownik {
    public:

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
    public:
    
        void pokazDane() {
            cout << "Nauczyciel: " << stanowisko << ". Na wiecej nie mam uprawnien ):" << endl;
        }
};

int main() {

    Administracja szefu;
    szefu.pokazDane();

    Nauczyciel kamil;
    kamil.pokazDane();

}