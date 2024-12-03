#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;
    string dataUrodzenia;
public:
    Osoba(const string& imie, const string& nazwisko, const string& dataUrodzenia): imie(imie), nazwisko(nazwisko), dataUrodzenia(dataUrodzenia) {}
    virtual ~Osoba() = default;
    
    virtual void przedstawSie() const {
        cout << "Imie: " << imie << ", Nazwisko: " << nazwisko 
             << ", Data urodzenia: " << dataUrodzenia << endl;
    }
};

class Nauczyciel : public Osoba {
private:
    vector<string> prowadzoneKursy;
public:
    Nauczyciel(const string& imie, const string& nazwisko, const string& dataUrodzenia) : Osoba(imie, nazwisko, dataUrodzenia) {}

    void dodajKurs(const string& kurs) {
        prowadzoneKursy.push_back(kurs);
    }

    void wyswietlKursy() const {
        cout << "Prowadzone kursy: ";
        for (const auto& kurs : prowadzoneKursy) {
            cout << kurs << ", ";
        }
        cout << endl;
    }
};

class Uczen : public Osoba {
private:
    vector<string> zapisaneKursy;
public:
    Uczen(const string& imie, const string& nazwisko, const string& dataUrodzenia) : Osoba(imie, nazwisko, dataUrodzenia) {}

    void zapiszNaKurs(const string& kurs) {
        zapisaneKursy.push_back(kurs);
    }

    void wyswietlKursy() const {
        cout << "Zapisane kursy: ";
        for (const auto& kurs : zapisaneKursy) {
            cout << kurs << ", ";
        }
        cout << endl;
    }
};

class Material {
private:
    string nazwaMaterialu;
    string typPliku;
public:
    Material(const string& nazwa, const string& typ) : nazwaMaterialu(nazwa), typPliku(typ) {}

    void wyswietlInfo() const {
        cout << "Material: " << nazwaMaterialu << ", Typ pliku: " << typPliku << endl;
    }
};

class SalaLekcyjna {
private:
    string numerSali;
    int pojemnosc;
public:
    SalaLekcyjna(const string& numer, int pojemnosc) : numerSali(numer), pojemnosc(pojemnosc) {}

    void wyswietlInfo() const {
        cout << "Sala: " << numerSali << ", Pojemnosc: " << pojemnosc << endl;
    }
};

class Kurs {
private:
    string nazwaKursu;
    string kodKursu;
    Nauczyciel* nauczyciel;
    SalaLekcyjna* sala;
    vector<Uczen*> uczniowie;
    vector<Material> materialy;
public:
    Kurs(const string& nazwa, const string& kod, Nauczyciel* nauczyciel, SalaLekcyjna* sala) : nazwaKursu(nazwa), kodKursu(kod), nauczyciel(nauczyciel), sala(sala) {}

    void dodajUcznia(Uczen* uczen) {
        uczniowie.push_back(uczen);
    }

    void dodajMaterial(const Material& material) {
        materialy.push_back(material);
    }

    void wyswietlInfo() const {
        cout << "Kurs: " << nazwaKursu << ", Kod: " << kodKursu << endl;
        if (nauczyciel) {
            cout << "Prowadzący: \n";
            nauczyciel->przedstawSie();
        }
        if (sala) {
            sala->wyswietlInfo();
        }
        cout << "Uczestnicy kursu: \n";
        for (const auto& uczen : uczniowie) {
            uczen->przedstawSie();
        }
        cout << "Materialy: \n";
        for (const auto& material : materialy) {
            material.wyswietlInfo();
        }
    }
};
int main() {

    Nauczyciel nauczyciel("Czarek", "S", "2003-05-15");
    Uczen uczen1("Mati", "P", "2007-09-12");
    Uczen uczen2("Piotr", "Gigant", "2004-11-22");
    SalaLekcyjna sala("101", 30);

    Kurs kurs("Matematyka", "MTH101", &nauczyciel, &sala);
    kurs.dodajUcznia(&uczen1);
    kurs.dodajUcznia(&uczen2);

    Material material1("Podstawy jezyka C#", "pdf");
    Material material2("Analiza matematyczna", "ppt");
    kurs.dodajMaterial(material1);
    kurs.dodajMaterial(material2);

    kurs.wyswietlInfo();

    return 0;
}