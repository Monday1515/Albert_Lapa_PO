#include <iostream> // poprawnie
#include <string>

using namespace std;

class Vehicle {
public:
    virtual void setAttrib() = 0;
    virtual int getWheels() = 0;
    virtual bool getEngine() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int wheels;
    bool engine;

public:
    void setAttrib() override {
        wheels = 4;
        engine = true;
    }
    int getWheels() override {
        return wheels;
    }
    bool getEngine() override {
        return engine;
    }
};

class Bike : public Vehicle {
    int wheels;
    bool engine;

public:
    void setAttrib() override {
        wheels = 2;
        engine = false;
    }
    int getWheels() override {
        return wheels;
    }
    bool getEngine() override {
        return engine;
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() {}
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        Vehicle* car = new Car();
        car->setAttrib();
        return car;
    }
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        Vehicle* bike = new Bike();
        bike->setAttrib();
        return bike;
    }
};

int main() {

    VehicleFactory* bikeFactory = new BikeFactory();
    Vehicle* bike = bikeFactory->createVehicle();
    cout << "Bike - Engine: " << bike->getEngine() << ", Wheels: " << bike->getWheels() << endl;

    VehicleFactory* carFactory = new CarFactory();
    Vehicle* car = carFactory->createVehicle();
    cout << "Car - Engine: " << car->getEngine() << ", Wheels: " << car->getWheels() << endl;

    delete bike;
    delete bikeFactory;
    delete car;
    delete carFactory;

    return 0;
}
