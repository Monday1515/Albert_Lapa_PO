import java.io.FileWriter; // poprawnie
import java.io.IOException;

// Klasa reprezentująca użytkownika
class User {
    private String name;
    private int age;

    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Gettery
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}

// Klasa odpowiedzialna za wyświetlanie danych użytkownika
class UserDisplayer {
    public void displayUser(User user) {
        System.out.println("Name: " + user.getName() + ", Age: " + user.getAge());
    }
}

// Klasa odpowiedzialna za zapisywanie danych użytkownika
class UserSaver {
    public void saveUser(User user, String filename) {
        try (FileWriter writer = new FileWriter(filename, true)) {
            writer.write("Name: " + user.getName() + ", Age: " + user.getAge() + "\n");
            System.out.println("User saved to file: " + filename);
        } catch (IOException e) {
            System.err.println("Error: Could not save user to file " + filename);
        }
    }
}

public class Lab7_zad1_java {
    public static void main(String[] args) {
        User user = new User("John Doe", 30);
        User user1 = new User("Czarek", 19);
        User user2 = new User("Mati", 20);

        UserDisplayer displayer = new UserDisplayer();
        UserSaver saver = new UserSaver();

        // Wyświetlanie użytkowników
        displayer.displayUser(user);
        displayer.displayUser(user1);
        displayer.displayUser(user2);

        // Zapisywanie użytkowników do pliku
        saver.saveUser(user, "users.txt");
        saver.saveUser(user1, "users.txt");
        saver.saveUser(user2, "users.txt");
    }
}
