#include <iostream>
using namespace std;

class Tablica {
public:

    int *Table; // jak poprzednio

    // Konstruktor domyślny
    Tablica() {
        Table = new int[10];
        cout << "Utworzono tablice konstruktorem domyślnym.\n";
    };
    
    // Konstruktor z parametrem
    Tablica(int size) {
        Table = new int[size];
        cout << "Utworzono tablice wielkosci " << size << " konstruktorem z parametrem.\n";
    };

    // Destruktor
    ~Tablica() {
        delete[] Table;
        cout << "Zwolniono pamiec.\n";
    };
   
};

int main() { // Prosze tworzyc obiekty takze w pamieci dyamicznej
  
    // Użycie konstruktora domyślnego
    Tablica tablica1;
  
    // Użycie konstruktora z argumentem
    Tablica tablica2(20);

    return 0;
}
