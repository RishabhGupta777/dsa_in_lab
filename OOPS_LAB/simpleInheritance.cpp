#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    string brand = "Toyota";
    int speed = 120;

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    string model = "Corolla";
};

int main() {
    Car car1;
    car1.displayInfo();
    cout << "Model: " << car1.model << endl;
    return 0;
}
