#include <iostream>
using namespace std;

class Osoba {

private:
    string imie;
    string nazwisko;
    int wiek;
    string email;
    string telefon;

public:

    // setters
    void setAttrib(string imie, string nazwisko, int wiek) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->wiek = wiek;
        cout << "Atrybuty przypisano.\n";
    }

    // setters with validation
    void setEmail(string email) {
        if (email.find("@") != string::npos) {
            cout << "Email przypisano.\n";
            this->email = email;
        }
        else cout << "Email nieprawidlowy!\n";
    }
    void setNumber(string telefon) {
        if (telefon.length() == 9) {
            cout << "Telefon przypisano.\n";
            this->telefon = telefon;
        }
        else cout << "Telefon nieprawidlowy!\n";
    }

    // getters
    string getName() {
        return imie;
    }
    string getSurname() {
        return nazwisko;
    }
    int getAge() {
        return wiek;
    }
    string getEmail() {
        return email;
    }
    string getNumber() {
        return telefon;
    }
   
};

int main() {

    Osoba przyjaciel1;
    przyjaciel1.setAttrib("Mateusz", "P", 20);
    przyjaciel1.setEmail("mati@op.pl");
    przyjaciel1.setNumber("123456789");
    
    cout << przyjaciel1.getName() << endl;
    cout << przyjaciel1.getSurname() << endl;
    cout << przyjaciel1.getAge() << endl;
    cout << przyjaciel1.getEmail() << endl;
    cout << przyjaciel1.getNumber() << endl;

}