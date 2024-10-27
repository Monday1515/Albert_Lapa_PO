#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Parrot {
    public:
    string phrase;

    void say(vector<string> wordsLearned) {
        wordsLearned.pop_back();
        int randomNum = rand() % wordsLearned.size();
        cout << "Papuga mowi: " << wordsLearned.at(randomNum) << endl;
        cout << "Nauczyła się dziś " << wordsLearned.size() << " słow.\n";
    }
};

int main() {

    Parrot papuga;
    string whatWillParrotSay;
    vector<string> words;
    cout << "Naucz papugę nowych słow: \nAby zakończyć naukę, powiedz stop.\n";
    while (whatWillParrotSay != "stop") {
        cin >> whatWillParrotSay;
        words.push_back(whatWillParrotSay);
    }
    papuga.say(words);

    return 0;
}