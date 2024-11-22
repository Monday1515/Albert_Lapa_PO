#include <iostream>
using namespace std;

class Silnikowy {
    public:
    void przyspiesz() {
        cout << "This car has an internal-combustion engine.\n";
    }
};
class Elektryczny {
    public:
    void ladowanie() {
        cout << "This car can be charged with electricity.\n";
    }
};
class Hybryda : public Silnikowy, public Elektryczny {
    public:
    void hybrydowy() {
        przyspiesz();
        ladowanie();
        cout << "This is a hybrid-powertrain car. You'll get an amazing milage with this one!\n";
    }
};

int main() {
    Hybryda Prius;
    Prius.hybrydowy();
}