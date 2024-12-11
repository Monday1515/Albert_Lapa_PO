#include <iostream>
using namespace std;

class Discount {
public:
    virtual double calculate(double price) const = 0; // obliczanie rabatu
    virtual ~Discount() = default;                    // w metodzie abstrakcyjnej
};

class RegularDiscount : public Discount {
public:
    double calculate(double price) const override {
        return price * 0.90; // 10% rabatu
    }
};

class SeasonalDiscount : public Discount {
public:
    double calculate(double price) const override {
        return price * 0.80; // 20% rabatu
    }
};

// zastosowanie rabatu 
void applyDiscount(const Discount& discount, double price) {
    cout << "Original price: " << price << endl;
    cout << "Price after discount: " << discount.calculate(price) << endl;
}

int main() {
    double price = 100.0;

    RegularDiscount regularDiscount;
    SeasonalDiscount seasonalDiscount;

    cout << "Applying regular discount:" << endl;
    applyDiscount(regularDiscount, price);

    cout << "Applying seasonal discount:" << endl;
    applyDiscount(seasonalDiscount, price);

    return 0;
}