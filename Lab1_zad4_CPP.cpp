#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Parrot {
    public:
    string phrase = "Opis";

    void say(string newPhrase, int howManyTimes) {
        phrase = newPhrase;
        int times = howManyTimes;
        for (int i = 0; i < times; i++) {
            cout << phrase << endl;
        }
    }
};

int main() {

    Parrot papuga;
    string whatWillParrotSay;
    int howManyTimeWillSay;
    cout << "Co powie papuga? "; cin >> whatWillParrotSay;
    cout << "Ile razy to powie? Podaj liczbę: "; cin >> howManyTimeWillSay;
    papuga.say(whatWillParrotSay, howManyTimeWillSay);

    return 0;
}