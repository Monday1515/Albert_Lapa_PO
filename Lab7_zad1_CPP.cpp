#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// dane osoby
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

    // wyświetlanie danych osoby
    void displayUser() const { // a tej metody własnie być nie powinno w tej klasie
        cout << "Name: " << name << ", Age: " << age << endl;
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

    User user1("Czarek", 21);
    User user2("Mati", 20);

    user1.displayUser();
    user2.displayUser();

    UserSaver saver;
    saver.saveUser(user1, "users.txt");
    saver.saveUser(user2, "users.txt");

    return 0;
}
