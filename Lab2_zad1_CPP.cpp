#include <iostream>
using namespace std;

class Samochod {
private:

public:

    string marka;
    string model;
    int rokProdukcji;

    // Konstruktor domyślny
    Samochod() {
        marka = "Toyota";
        model = "Corolla";
        rokProdukcji = 2003;
    };
   
    // Konstruktor z argumentami
    Samochod(string make, string carModel, int year) {
        marka = make;
        model = carModel;
        rokProdukcji = year;
    };
    
    // Destruktor
    ~Samochod() {
        cout << "Destruktor wywołany dla: " << marka << " " << model << endl;
    }
   
    // Metoda wyświetlania danych
    void wyswietlDane() {
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Rok produkcji: " << rokProdukcji << endl;
    }
};

int main() {

    // Utworzenie obiektu z użyciem konstruktora domyślnego
    Samochod mojSamochod1;

    // Utworzenie obiektu z użyciem konstruktora z argumentami
    Samochod mojSamochod2("Honda", "Civic", 2008);
    Samochod mojSamochod3("Volkswagen", "Passat", 2021);

    mojSamochod1.wyswietlDane();
    mojSamochod2.wyswietlDane();
    mojSamochod3.wyswietlDane();

    return 0;  // Destruktory są wywoływane tutaj
}