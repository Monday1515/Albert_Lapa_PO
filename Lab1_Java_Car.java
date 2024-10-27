// export CPPFLAGS="-I/opt/homebrew/opt/openjdk/include"
import java.util.*; 
import java.time.*;

public class Lab1_Java_Car {

    String make;
    String model;
    int year;
    int currentYear = Year.now().getValue();

    public Lab1_Java_Car(String make, String model, int year) { // constructor
        this.make = make;
        this.model = model;
        this.year = year;
    }

    public void displayInfo() {
        System.out.println("You are looking at a magestic " + make + " " + model + " " + year);
    }

    public int getCarAge() {
        return currentYear - year;
    }

    public boolean isSameCar(String otherMake, String otherModel, int otherYear) {
        System.out.println("We are comparing a " + year + " " + make + " " + model + " and a " + otherYear + " " + otherMake + " " + otherModel);
        if (make == otherMake && model == otherModel && year == otherYear) {
            return true;
        }
        else {
            return false;
        }
    }

    public static void main(String[] args) {
        System.out.println("Hello, World!");

        Lab1_Java_Car myCar1 = new Lab1_Java_Car("Toyota", "Corolla", 2003);
        Lab1_Java_Car myCar2 = new Lab1_Java_Car("Volkswagen", "Passat", 2021);
        Lab1_Java_Car myCar3 = new Lab1_Java_Car("Toyota", "Corolla", 2003);

        myCar1.displayInfo();

        System.out.println("This car's age is " + myCar1.getCarAge());

        boolean areSame = myCar1.isSameCar(myCar2.make, myCar2.model, myCar2.year);
        if (areSame == true) {
            System.out.println("Those cars are the same.");
        }
        else {
            System.out.println("Those cars are NOT the same.");
        }

    }
}