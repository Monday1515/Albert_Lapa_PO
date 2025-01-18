#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
private:
    string name;
    int age;

public:
    User(const string& name, int age) : name(name), age(age) {}

    // gettery
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

// wyświetlanie danych osoby
class UserDisplayer {
public:
    void displayUser(const User& user) const {
        cout << "Name: " << user.getName() << ", Age: " << user.getAge() << endl;
    }
};

// zapis danych osoby do pliku
class UserSaver {
public:
    void saveUser(const User& user, const string& filename) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << "Name: " << user.getName() << ", Age: " << user.getAge() << endl;
            file.close();
            cout << "User saved to file: " << filename << endl;
        } else {
            cerr << "Error: Could not open file " << filename << endl;
        }
    }
};

int main() {

    User user("John Doe", 30);
    User user1("Czarek", 19);
    User user2("Mati", 20);

    UserDisplayer displayer;
    UserSaver saver;

    displayer.displayUser(user);
    displayer.displayUser(user1);
    displayer.displayUser(user2);

    saver.saveUser(user, "users.txt");
    saver.saveUser(user1, "users.txt");
    saver.saveUser(user2, "users.txt");

    return 0;
}
