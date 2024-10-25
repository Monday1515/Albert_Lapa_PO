#include <iostream>
#include <ctime>
using namespace std;

class Car {
    public:

    string make;
    string model;
    int year;

    time_t timestamp = time(NULL);
    tm *const pTInfo = localtime(&timestamp);
    int currentYear = 1900 + pTInfo->tm_year;

    Car(string make, string model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
        // cout << "Constructed\n";
    };

    ~Car() {
        // cout << "Deconstructed\n";
    };

    void displayInfo() {
        cout << "Brand: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Production year: " << year << endl;
    }

    int getCarAge() {
        return currentYear-year;
        // cout << "This " << model << " is " << currentYear-year << " years old.\n";
    }

    bool isSameCar(Car otherCar) {
        string otherMake = otherCar.make;
        string otherModel = otherCar.model;
        int otherYear = otherCar.year;

        if (make == otherMake && year == otherYear && model == otherModel) {
            return true;
        }
        else {
            return false;
        }
    }
   
};

int main() {

    Car myCar1("Toyota", "Corolla", 2003);
    Car myCar2("Fisker", "Ocean", 2024);
    Car myCar3("Volkswagen", "Passat", 2021);
    Car myCar4("Toyota", "Corolla", 2003);

    myCar1.displayInfo();
    cout << myCar1.getCarAge() << endl;

    bool ifSame = myCar1.isSameCar(myCar4);
    if (ifSame == true) {
        cout << "Samochody są takie same.";
    };
    if (ifSame == false) {
        cout << "Samochody nie są takie same.";
    };

    return 0;
}